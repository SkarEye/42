/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:22:25 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/22 16:13:23 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <climits>

#include "BitcoinExchange.hpp"

#define LOG_ERROR(x)	std::cerr << "Error: " << x << std::endl

static std::string trim(const std::string& s)
{
    std::string::size_type a = s.find_first_not_of(" \t\r\n");
    std::string::size_type b = s.find_last_not_of(" \t\r\n");
    if (a == std::string::npos) return "";
    return s.substr(a, b - a + 1);
}

static bool isAllDigits(const std::string& s)
{
	if (s.empty()) return false;
	for (std::string::size_type i = 0; i < s.size(); ++i)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

static bool	stringToInt(const std::string &s, int &out)
{
	std::stringstream	ss(s);
	long				tmp;

	ss >> tmp;
	if (ss.fail() || !ss.eof())
		return (false);
	if (tmp < (long)INT_MIN || tmp > (long)INT_MAX)
		return (false);
	out = (int)tmp;
	return (true);
}

static bool stringToFloat(const std::string& s, float& out)
{
	if (s.empty()) return false;

	std::istringstream iss(s);
	iss >> std::noskipws;          // reject leading whitespace
	double tmp;
	iss >> tmp;
	if (iss.fail()) return false;

	// Must consume the entire string
	char leftover;
	if (iss >> leftover) return false;

	// Reject NaN / Inf (tmp != tmp is the classic NaN test)
	if (tmp != tmp) return false;
	if (tmp >  3.4e38 || tmp < -3.4e38) return false;  // float range

	out = static_cast<float>(tmp);
	return true;
}

static bool	isValidDate(const std::string& date, int l)
{	
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		LOG_ERROR("(l. " << l << "), date format wrong (YYYY-MM-DD): [" << date << "]");
		return (false);
	}

	std::string year_str  = date.substr(0, 4);
	std::string month_str = date.substr(5, 2);
	std::string day_str   = date.substr(8, 2);

	if (!isAllDigits(year_str) || !isAllDigits(month_str) || !isAllDigits(day_str))
	{
		LOG_ERROR("(l. " << l << "), date contains non-digit characters: [" << date << "]");
		return (false);
	}

	int	year, month, day;
	stringToInt(year_str, year);
	stringToInt(month_str, month);
	stringToInt(day_str, day);

	if (year < 1970 || year > 2100)
	{
		LOG_ERROR("(l. " << l << "), 'year' is out of range (1970 - 2100): [" << year_str << "]");
		return (false);
	}

	if (month < 1 || month > 12)
	{
		LOG_ERROR("(l. " << l << "), 'month' is out of range (01 - 12): [" << month_str << "]");
		return (false);
	}
	
	static const int	days_in_month[] = {31,28,31,30,31,30,
										   31,31,30,31,30,31};
	bool				is_leap_year = year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
	int max_day = days_in_month[month - 1] + (month == 2 && is_leap_year ? 1 : 0);
	
	if (day < 1 || day > max_day)
	{
		LOG_ERROR("(l. " << l << "), 'day' is not valid: [" + day_str + "]");
		return (false);
	}

	return (true);
}

void	BitcoinExchange::loadDataBase(const std::string& filepath)
{
	std::ifstream	in(filepath.c_str());
	if (!in.is_open())
		throw FileOpenException();

	std::string	line;
	int	l = 0;

	if (std::getline(in, line))
	{
		++l;
		if (trim(line) != "date,exchange_rate")
		{
			LOG_ERROR("database header missing or malformed: [" << line << "]");
			in.seekg(0);  // re-read first line as data
			l = 0;
		}
	}

	while (std::getline(in, line))
	{
		++l;

		std::string::size_type	comma = line.find(',');
		if (comma == std::string::npos)
		{
			LOG_ERROR("(l. " << l << "), line does not have a valid seperator `|'");
			continue;
		}

		std::string	date = trim(line.substr(0, comma));

		if (!isValidDate(date, l))
			continue;

		std::string	rate = trim(line.substr(comma + 1));

		float r;
		if (!stringToFloat(rate, r))
		{
			LOG_ERROR("(l. " << l << "), rate is not a valid number: [" << rate << "]");
			continue;
		}
		if (r < 0.0f)
		{
			LOG_ERROR("(l. " << l << "), rate is negative: [" << rate << "]");
			continue;
		}
		_db[date] = r;
	}

	if (_db.empty())
		throw EmptyDataBaseException();
}

bool	BitcoinExchange::lookupRate(const std::string& date, float& out) const
{
	std::map<std::string, float>::const_iterator it = this->_db.lower_bound(date);

	if (it == this->_db.end() || it->first != date)
	{
		if (it == this->_db.begin())
			return (false);
		--it;
	}

	out = it->second;
	return (true);
}

const char*	BitcoinExchange::FileOpenException::what() const throw()
{
	return ("could not open file.");
}

const char*	BitcoinExchange::EmptyDataBaseException::what() const throw()
{
	return ("database is empty or could not be loaded.");
}

BitcoinExchange::BitcoinExchange(void) : _loaded(false)
{
	try
	{
		loadDataBase(DATA_FILEPATH);
		_loaded = true;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _db(other._db), _loaded(other._loaded) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_db = other._db;
		this->_loaded = other._loaded;
	}
	return (*this);
}


void	BitcoinExchange::processInput(const std::string& filepath)
{
	if (!_loaded)
		throw EmptyDataBaseException();

	std::ifstream	in(filepath.c_str());
	if (!in.is_open())
		throw FileOpenException();

	std::string	line;
	int	l = 0;

	if (std::getline(in, line))
	{
		++l;
		if (trim(line) != "date | value")
		{
			LOG_ERROR("input header missing or malformed: [" << line << "]");
			in.seekg(0);  // re-read first line as data
			l = 0;
		}
	}

	while (std::getline(in, line))
	{
		++l;
		
		std::string::size_type	v_bar = line.find('|');
		if (v_bar == std::string::npos)
		{
			LOG_ERROR("(l. " << l << "), line does not have a valid seperator `|'");
			continue;
		}

		std::string	date = trim(line.substr(0, v_bar));

		if (!isValidDate(date, l))
			continue;

		std::string	value = trim(line.substr(v_bar + 1));

		float v;
		if (!stringToFloat(value, v))
		{
			LOG_ERROR("(l. " << l << "), value is not a valid number: [" << value << "]");
			continue;
		}
		if (v < 0.0f)
		{
			LOG_ERROR("(l. " << l << "), value is negative: [" << v << "]");
			continue;
		}
		if (v > 1000.0f)
		{
			LOG_ERROR("(l. " << l << "), value is too large: [" << v << "]");
			continue;
		}

		float	r;
		
		if (!lookupRate(date, r))
		{
			LOG_ERROR("(l. " << l << "), date is earlier than any record: [" << date << "]");
			continue;
		}

		std::cout << date << " => " << v << " = " << v * r << std::endl;
	}
}
