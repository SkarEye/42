/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:22:09 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/06/02 12:00:50 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <exception>

# define DATA_FILEPATH "data.csv"

class	BitcoinExchange
{
	private:
		std::map<std::string, float>	_db;
		bool							_loaded;

		void	loadDataBase(const std::string& filepath);

		bool	lookupRate(const std::string& date, float& out) const;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange& other);
		
		void	processInput(const std::string& filepath);

		class	FileOpenException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	EmptyDataBaseException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
