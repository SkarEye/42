/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:20:07 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/25 16:00:50 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
# define RPN_H

# include <string>
# include <exception>

class RPN
{
	private:
		RPN(void);
		RPN(const RPN& other);
		~RPN();

		RPN&	operator=(const RPN& other);

	public:
		static int	calculate(const std::string& str);

		class RPNException : public std::exception
		{
			private:
				std::string	_msg;
			public:
				RPNException(const std::string& msg) : _msg(msg) {}
				virtual ~RPNException() throw() {}
				virtual const char* what() const throw() { return (_msg.c_str()); }
		};
};

#endif