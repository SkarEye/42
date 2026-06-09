/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:40:30 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/20 18:43:33 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstddef>

#include "Span.hpp"

#define ANSI_RESET	"\033[0m"
#define ANSI_RED	"\033[31m"

Span::Span(void) :
	_size(0)
{}

Span::Span(unsigned int n) :
	_size(n)
{}

Span::Span(const Span& other) :
	_size(other._size),
	_storage(other._storage)
{}

Span::~Span()
{}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_storage = other._storage;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_storage.size() >= this->_size)
		throw SpanFullException();
	this->_storage.insert(this->_storage.end(), n);
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->_storage.size() < 2)
		throw SpanEmptyException();

	std::vector<int> sorted(this->_storage);
	std::sort(sorted.begin(), sorted.end());

	unsigned int	span = static_cast<unsigned int>(sorted[1]) - static_cast<unsigned int>(sorted[0]);
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		unsigned int	curr = static_cast<unsigned int>(sorted[i]) - static_cast<unsigned int>(sorted[i - 1]);
		if (curr < span)
			span = curr;
	}
	return (span);
}

unsigned int	Span::longestSpan(void) const
{
	if (this->_storage.size() < 2)
		throw SpanEmptyException();

	return (static_cast<unsigned int>(*std::max_element(this->_storage.begin(), this->_storage.end()))
		  - static_cast<unsigned int>(*std::min_element(this->_storage.begin(), this->_storage.end())));
}

const char*	Span::SpanFullException::what() const throw()
{
	return (ANSI_RED " Span: Insufficient space in storage !" ANSI_RESET);
}

const char*	Span::SpanEmptyException::what() const throw()
{
	return (ANSI_RED " Span: Insufficient numbers in storage !" ANSI_RESET);
}
