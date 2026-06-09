/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:35:23 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 21:04:36 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T> class Array
{
	private:
		unsigned int	_n;
		T*				_storage;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		~Array();

		Array&		operator=(const Array& other);
		T&			operator[](unsigned int n);
		const T&	operator[](unsigned int n) const;

		unsigned int	size(void) const;

		class OutOfBounds : public std::exception
		{
			public:
				virtual const char* what(void) const throw();
		};
};

# include "Array.tpp"

#endif