/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:33:33 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/18 16:20:05 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include <cstddef>
#include <cfloat>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>

#include "ScalarConverter.hpp"

#define ANSI_RESET		"\033[0m"
#define ANSI_RED		"\033[31m"

#define IS_DISPLAYABLE	0x01
#define IS_POSSIBLE		0x02
#define IS_NEGINF		0x04
#define IS_POSINF		0x08
#define IS_NAN			0x10

typedef enum	e_type
{
	T_CHAR = 0,
	T_INT = 1,
	T_FLOAT = 2,
	T_DOUBLE = 3,
	T_NEGINF,
	T_POSINF,
	T_NAN,
	T_INVALID,
}	t_type;

typedef struct	s_data
{
	double	d;
	float	f;
	int		i;
	char	c;

	char	double_flags;
	char	float_flags;
	char	int_flags;
	char	char_flags;
}	t_data;

static bool	isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

static t_type	getPseudoType(const std::string& l)
{
	if (l == "-inf" || l == "-inff")
		return (T_NEGINF);
	if (l == "+inf" || l == "+inff")
		return (T_POSINF);
	if (l == "nan"  || l == "nanf")
		return (T_NAN);
	return (T_INVALID);
}

static t_type	getNumericType(const std::string& l)
{
	size_t	i = 0;
	size_t	len = l.length();

	if (len == 0)
		return (T_INVALID);

	if (l[0] == '+' || l[0] == '-')
		i = 1;

	size_t	body_start = i;
	size_t	dot_pos = std::string::npos;
	bool	has_f = false;

	for (; i < len; ++i)
	{
		if (l[i] == '.')
		{
			if (dot_pos != std::string::npos)
				return (T_INVALID);
			dot_pos = i;
		}
		else if (l[i] == 'f')
		{
			if (i != len - 1)
				return (T_INVALID);
			has_f = true;
		}
		else if (!isDigit(l[i]))
			return (T_INVALID);
	}

	bool	has_any_digit = false;

	for (size_t k = body_start; k < len; ++k)
	{
		if (isDigit(l[k]))
		{
			has_any_digit = true;
			break ;
		}
	}
	if (!has_any_digit)
		return (T_INVALID);

	if (dot_pos == std::string::npos)
	{
		if (has_f)
			return (T_INVALID);
		return (T_INT);
	}

	return (has_f ? T_FLOAT : T_DOUBLE);
}

static t_type	getType(const std::string& l)
{
	if (l.empty())
		return (T_INVALID);

	t_type pseudo = getPseudoType(l);
	if (pseudo != T_INVALID)
		return (pseudo);

	if (l.length() == 1 && !isDigit(l[0]))
		return (T_CHAR);

	return (getNumericType(l));
}

static bool	string_to_int(const std::string &s, int &out)
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

static bool string_to_float(const std::string &s, float &out)
{
	std::string		body = s;
	if (!body.empty() && body[body.size() - 1] == 'f')
		body.erase(body.size() - 1);

	std::stringstream	ss(body);
	double				tmp;

	ss >> tmp;
	if (ss.fail() || !ss.eof())
		return (false);
	if (tmp < -(double)FLT_MAX || tmp > (double)FLT_MAX)
		return (false);
	out = (float)tmp;
	return (true);
}

static bool string_to_double(const std::string &s, double &out)
{
	std::stringstream ss(s);

	ss >> out;
	if (ss.fail() || !ss.eof())
		return (false);
	return (true);
}

static t_data	getData(const std::string& l, t_type type)
{
	t_data	d = {0, 0, 0, 0,
	0, 0, 0, 0};

	switch (type)
	{
		case T_CHAR:
		{
			d.c = l[0];
			d.i = static_cast<int>(d.c);
			d.f = static_cast<float>(d.c);
			d.d = static_cast<double>(d.c);

			d.char_flags |= IS_POSSIBLE;
			if (d.c >= 32 && d.c <= 126)
				d.char_flags |= IS_DISPLAYABLE;
			d.int_flags |= IS_POSSIBLE;
			d.float_flags |= IS_POSSIBLE;
			d.double_flags |= IS_POSSIBLE;

			break ;
		}
		case T_INT:
		{
			if (string_to_int(l, d.i))
			{
				d.c = static_cast<char>(d.i);
				d.f = static_cast<float>(d.i);
				d.d = static_cast<double>(d.i);

				if (d.i >= -128 && d.i <= 127)
				{
					d.char_flags |= IS_POSSIBLE;
					if (d.c >= 32 && d.c <= 126)
						d.char_flags |= IS_DISPLAYABLE;
				}
				d.int_flags |= IS_POSSIBLE;
				d.float_flags |= IS_POSSIBLE;
				d.double_flags |= IS_POSSIBLE;
			}
			else if (string_to_double(l, d.d))
			{
				d.f = static_cast<float>(d.d);
				if (d.d >= -(double)FLT_MAX && d.d <= (double)FLT_MAX)
					d.float_flags |= IS_POSSIBLE;
				d.double_flags |= IS_POSSIBLE;
			}

			break ;
		}
		case T_FLOAT:
		{
			if (!string_to_float(l, d.f))
				break ;
			d.c = static_cast<char>(d.f);
			d.i = static_cast<int>(d.f);
			d.d = static_cast<double>(d.f);

			if (d.f >= -128.0f && d.f <= 127.0f && std::fmod(d.f, 1.0f) == 0.0f)
			{
				d.char_flags |= IS_POSSIBLE;
				if (d.c >= 32 && d.c <= 126)
					d.char_flags |= IS_DISPLAYABLE;
			}
			if (d.f >= (float)INT_MIN && d.f <= (float)INT_MAX)
				d.int_flags |= IS_POSSIBLE;
			d.float_flags |= IS_POSSIBLE;
			d.double_flags |= IS_POSSIBLE;

			break ;
		}
		case T_DOUBLE:
		{
			if (!string_to_double(l, d.d))
				break ;
			d.c = static_cast<char>(d.d);
			d.i = static_cast<int>(d.d);
			d.f = static_cast<float>(d.d);

			if (d.d >= -128.0 && d.d <= 127.0 && std::fmod(d.d, 1.0) == 0.0)
			{
				d.char_flags |= IS_POSSIBLE;
				if (d.c >= 32 && d.c <= 126)
					d.char_flags |= IS_DISPLAYABLE;
			}
			if (d.d >= (double)INT_MIN && d.d <= (double)INT_MAX)
				d.int_flags |= IS_POSSIBLE;
			if (d.d >= -(double)FLT_MAX && d.d <= (double)FLT_MAX)
				d.float_flags |= IS_POSSIBLE;
			d.double_flags |= IS_POSSIBLE;

			break ;
		}
		case T_NEGINF:
		{
			d.float_flags |= IS_POSSIBLE | IS_NEGINF;
			d.double_flags |= IS_POSSIBLE | IS_NEGINF;

			break ;

		}
		case T_POSINF:
		{
			d.float_flags |= IS_POSSIBLE | IS_POSINF;
			d.double_flags |= IS_POSSIBLE | IS_POSINF;

			break ;
		}
		case T_NAN:
		{
			d.float_flags |= IS_POSSIBLE | IS_NAN;
			d.double_flags |= IS_POSSIBLE | IS_NAN;

			break ;
		}
		case T_INVALID:
		{}
	}
	return (d);
}	

static void	printFloat(float v)
{
	if (std::fmod(v, 1.0f) == 0.0f)
		std::cout << std::fixed << std::setprecision(1) << v << "f";
	else
		std::cout << v << "f";
}

static void	printDouble(double v)
{
	if (std::fmod(v, 1.0) == 0.0)
		std::cout << std::fixed << std::setprecision(1) << v;
	else
		std::cout << v;
}

static void	handleData(t_data d)
{
	std::cout << "char  : ";
	if (d.char_flags & IS_POSSIBLE)
	{
		if (d.char_flags & IS_DISPLAYABLE)
			std::cout << "`" << d.c << "'";
		else
		 	std::cout << "Non displayable";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;

	std::cout << "int   : ";
	if (d.int_flags & IS_POSSIBLE)
		std::cout << d.i;
	else
		std::cout << "impossible";
	std::cout << std::endl;

	std::cout << "float : ";
	if (d.float_flags & IS_POSSIBLE)
	{
		if (d.float_flags & IS_NEGINF)
			std::cout << "-inff";
		else if (d.float_flags & IS_POSINF)
			std::cout << "+inff";
		else if (d.float_flags & IS_NAN)
			std::cout << "nanf";
		else
			printFloat(d.f);
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;

	std::cout << "double: ";
	if (d.double_flags & IS_POSSIBLE)
	{
		if (d.double_flags & IS_NEGINF)
			std::cout << "-inf";
		else if (d.double_flags & IS_POSINF)
			std::cout << "+inf";
		else if (d.double_flags & IS_NAN)
			std::cout << "nan";
		else
			printDouble(d.d);
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& l)
{
	t_type type = getType(l);
	if (type == T_INVALID)
	{
		std::cout << ANSI_RED "Error: invalid literal" ANSI_RESET << std::endl;
		return ;
	}
	handleData(getData(l, type));
}
