/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 19:46:28 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 21:03:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

# define ANSI_RESET		"\033[0m"
# define ANSI_RED		"\033[31m"

# ifdef DEBUG

#  include <iostream>

#  define ANSI_BOLD		"\033[1m"
#  define ANSI_MAGENTA	"\033[35m"
#  define ANSI_BMAGENTA	"\033[95m"

#  define LOG_DEBUG(x) \
	do { \
		std::cout	<< ANSI_BMAGENTA << ANSI_BOLD \
					<< "[DEBUG] " \
					<< ANSI_RESET << ANSI_MAGENTA \
					<< x \
					<< ANSI_RESET \
					<< std::endl; \
	} while (0)
# else
#  define LOG_DEBUG(x) do {} while (0)
# endif

template <typename T>
Array<T>::Array(void) :
	_n(0),
	_storage(new T[0]())
{
	LOG_DEBUG("[Array] Default constructor called");
}

template <typename T>
Array<T>::Array(unsigned int n) :
	_n(n),
	_storage(new T[n]())
{
	LOG_DEBUG("[Array] Size constructor called");
}

template <typename T>
Array<T>::Array(const Array& other) :
	_n(other._n),
	_storage(new T[other._n]())
{
	LOG_DEBUG("[Array] Copy constructor called");
	
	for (unsigned int i = 0; i < this->_n; ++i)
		this->_storage[i] = other._storage[i];
}

template <typename T>
Array<T>::~Array(void)
{
	LOG_DEBUG("[Array] Destructor called");

	delete[] this->_storage;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	LOG_DEBUG("[Array] Copy assignment operator called");
	if (this != &other)
	{
		T*	tmp = new T[other._n]();
		for (unsigned int i = 0; i < other._n; ++i)
			tmp[i] = other._storage[i];
		delete[] this->_storage;
		this->_storage = tmp;
		this->_n = other._n;
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](unsigned int n)
{
	if (n >= this->_n)
		throw typename Array<T>::OutOfBounds();
	return (this->_storage[n]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int n) const
{
	if (n >= this->_n)
		throw typename Array<T>::OutOfBounds();
	return (this->_storage[n]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_n);
}

template <typename T>
const char*	Array<T>::OutOfBounds::what(void) const throw()
{
	return (ANSI_RED "Index out of bounds." ANSI_RESET);
}

#endif
