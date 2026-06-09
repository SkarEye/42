/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:50:23 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/20 18:16:46 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_storage;
	
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		~Span();

		Span&	operator=(const Span& other);

		void	addNumber(int n);
		template <typename Iter>
		void	addRange(Iter first, Iter last)
		{
			if (this->_storage.size() + static_cast<unsigned int>(std::distance(first, last)) > this->_size)
				throw SpanFullException();
			this->_storage.insert(_storage.end(), first, last);
		}

		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class SpanFullException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class SpanEmptyException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

#endif
