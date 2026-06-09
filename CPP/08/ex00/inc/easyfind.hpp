/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:09:19 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/20 16:50:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>

# define ANSI_RED	"\033[31m"
# define ANSI_RESET	"\033[0m"


class NotFoundException : public std::exception
{
	public:
		const char* what() const throw() {return (ANSI_RED "Value not found in container" ANSI_RESET);}
};

template <typename T>
typename T::iterator	easyfind(T& container, int x)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), x);

	if (iter == container.end())
		throw NotFoundException();
	return (iter);
}

#endif
