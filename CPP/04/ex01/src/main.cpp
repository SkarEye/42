/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 14:54:02 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "Ansi.hpp"

int	main(void)
{
	LOG_INFO("Starting Brain basic set/get test (1/7)...\n");
	{
		Cat cat;

		cat.setIdea(0, "Think about lasagnas");
		cat.setIdea(1, "Wonder if today is Monday");

		std::cout << "Idea[0]: " << cat.getIdea(0) << '\n';
		std::cout << "Idea[1]: " << cat.getIdea(1) << '\n';
		std::cout << "Idea[2]: " << cat.getIdea(2) << '\n';
		std::cout << "Idea[-1]: " << cat.getIdea(-1) << '\n';
		std::cout << "Idea[101]: " << cat.getIdea(101) << '\n';

	}
	std::cout << '\n';
	LOG_INFO("Starting deep copy test via copy constructor (2/7)...\n");
	{
		Cat original;
		original.setIdea(0, "I want fish kibble");

		Cat copy(original);

		original.setIdea(0, "Actually... I want chicken kibble");

		std::cout << "Original's idea[0]: " << original.getIdea(0) << '\n';
		std::cout << "Copy's idea[0]: " << copy.getIdea(0) << '\n';
		// If deep copy is correct, copy should still say "I want fish kibble"
	}
	std::cout << '\n';
	LOG_INFO("Starting deep copy test via assignment operator (3/7)...\n");
	{
		Dog dog1;
		Dog dog2;

		dog1.setIdea(0, "Chase own tail");

		dog2 = dog1;

		dog1.setIdea(0, "Obnoxiously bark instead");

		std::cout << "dog1 idea[0]: " << dog1.getIdea(0) << '\n';
		std::cout << "dog2 idea[0]: " << dog2.getIdea(0) << '\n';
		// dog2 should still say "Chase own tail"
	}
	std::cout << '\n';
	LOG_INFO("Starting subject-style array test (5/7)...\n");
	{
		const int size = 10;
		Animal* animals[size];

		for (int i = 0; i < size; i++)
		{
			if (i < size / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		for (int i = 0; i < size; i++)
			delete animals[i];
	}
	std::cout << '\n';

	LOG_INFO("Starting self-assignment Brain safety test (6/7)...\n");
	{
		Dog	dog;

		dog.setIdea(0, "Slobber everywhere");

		Dog	&ref = dog;

		std::cout << "idea[0] after self-assignment: " << ref.getIdea(0) << '\n';
	}
	std::cout << '\n';
	LOG_INFO("Starting pointer comparison test (7/7)...\n");
	{
		Cat cat1;
		Cat cat2(cat1);

		cat1.setIdea(0, "Fish");
		cat2.setIdea(0, "Bird");

		std::cout << "cat1 idea: " << cat1.getIdea(0) << '\n';
		std::cout << "cat2 idea: " << cat2.getIdea(0) << '\n';
	}
	std::cout << '\n';
	LOG_SUCCESS("All tests completed.\n");
}
