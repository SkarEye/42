/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:57:32 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 15:32:53 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Base.hpp"

#define ANSI_RESET	"\033[0m"
#define ANSI_ITALIC	"\033[3m"
#define ANSI_BLACK	"\033[30m"
#define ANSI_RED	"\033[31m"

Base::~Base() {}

Base*	generate(void)
{
	int	r;
	
	r = std::rand() % 3;

	switch (r)
	{
		case 0:
		{
			std::cout << ANSI_BLACK ANSI_ITALIC << "Creating A..." ANSI_RESET << std::endl;
			return new A;
		}
		case 1:
		{
			std::cout << ANSI_BLACK ANSI_ITALIC << "Creating B..." ANSI_RESET << std::endl;
			return new B;
		}
		case 2:
		{
			std::cout << ANSI_BLACK ANSI_ITALIC << "Creating C..." ANSI_RESET << std::endl;
			return new C;
		}
	}
	return (nullptr);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
	 	std::cout << ANSI_RED "Error: cannot identify pointer type" ANSI_RESET << std::endl;
}

void	identify(Base& r)
{
	try
	{
		(void)dynamic_cast<A&>(r);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(r);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(r);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}
	
	std::cout << ANSI_RED "Error: cannot identify reference type" ANSI_RESET << std::endl;
}
