/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:27:39 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 10:35:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str;
	std::string* stringPTR = &str;
	std::string& stringREF = str;

	str = "HI THIS IS BRAIN";

	std::cout	<< "The address of `str' is       : "
				<< "[" << &str << "]"
				<< std::endl;
	std::cout	<< "The address of `stringPTR' is : "
				<< "[" << &stringPTR << "]"
				<< std::endl;
	std::cout	<< "The address of `stringREF' is : "
				<< "[" << &stringREF << "]"
				<< std::endl;
	
	std::cout << std::endl;

	std::cout	<< "`str' contains       : "
				<< "[" << str << "]"
				<< std::endl;
	std::cout	<< "`stringPTR' contains : "
				<< "[" << stringPTR << "]"
				<< std::endl;
	std::cout	<< "`stringREF' contains : "
				<< "[" << stringREF << "]"
				<< std::endl;
	return (0);
}
