/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 15:50:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/18 16:53:51 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Data.hpp"
#include "Serializer.hpp"

int	main(void)
{
	Data	d;

	d.str = "Some data";
	d.value = 42;

	Data*	original = &d;
	Data*	restored = Serializer::deserialize(Serializer::serialize(original));

	std::cout	<< "Before serialization:" << std::endl
				<< "Ptr addr   : " << original << std::endl
				<< "Stored str : " << original->str << std::endl
				<< "Stored val : " << original->value <<std::endl;

	std::cout	<< "After serialization:" << std::endl
				<< "Ptr addr   : " << restored << std::endl
				<< "Stored str : " << restored->str << std::endl
				<< "Stored val : " << restored->value <<std::endl;	

	return (0);
}