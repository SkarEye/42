/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 14:40:44 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 15:29:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Base.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 5; i++)
	{
		Base*	p = generate();
		identify(p);
		identify(*p);
		delete p;
	}
	return (0);
}