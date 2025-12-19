/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:29:23 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 15:33:37 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int	main(void)
{
	int	status = 0;
	
	LOG_INFO("Starting round of tests (1/1)...");
	{
		Fixed	a;
		Fixed	const b(10);
		Fixed	const c(42.42f);
		Fixed	const d(b);

		a = Fixed(1234.4321f);
		
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		
		LOG_SUCCESS("First round completed");
	}
	return (status);
}
