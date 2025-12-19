/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:52:52 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/13 20:03:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

# define ANSI_RED		"\033[31m"
# define ANSI_BRED		"\033[91m"

# define ANSI_GREEN		"\033[32m"
# define ANSI_BGREEN	"\033[92m"

# define ANSI_YELLOW	"\033[33m"
# define ANSI_BYELLOW	"\033[93m"

# define ANSI_CYAN		"\033[36m"
# define ANSI_BCYAN		"\033[96m"

# define ANSI_PURPLE	"\033[35m"
# define ANSI_BPURPLE	"\033[95m"

# define ANSI_BOLD		"\033[1m"
# define ANSI_RESET		"\033[0m"

# ifdef DEBUG
#  define LOG_DEBUG(x) \
	do { \
		std::cout	<< ANSI_BPURPLE << ANSI_BOLD \
					<< "[DEBUG] " \
					<< ANSI_RESET << ANSI_PURPLE \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
# else
#  define LOG_DEBUG(x) do {} while (0)
# endif

# ifndef SILENT
#  define LOG_SUCCESS(x) \
	do { \
		std::cout	<< ANSI_BGREEN << ANSI_BOLD \
					<< "[SUCCESS] " \
					<< ANSI_RESET << ANSI_GREEN \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
#  define LOG_WARNING(x) \
	do { \
		std::cout	<< ANSI_BYELLOW << ANSI_BOLD \
					<< "[WARNING] " \
					<< ANSI_RESET << ANSI_YELLOW \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
#  define LOG_ERROR(x) \
	do { \
		std::cout	<< ANSI_BRED << ANSI_BOLD \
					<< "[ERROR] " \
					<< ANSI_RESET << ANSI_RED \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
#  define LOG_INFO(x) \
	do { \
		std::cout	<< ANSI_BCYAN << ANSI_BOLD \
					<< "[INFO] " \
					<< ANSI_RESET << ANSI_CYAN \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
# else
#  define LOG_SUCCESS(x) do {} while (0)
#  define LOG_WARNING(x) do {} while (0)
#  define LOG_ERROR(x) do {} while (0)
#  define LOG_INFO(x) do {} while (0)
# endif

class	Fixed
{
	private:
		int					_n;
		static const int	_fPoint = 8;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &other);
		Fixed& operator=(const Fixed &other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool 	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed&b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed&b);

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);


#endif