/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 15:03:44 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "Ansi.hpp"

int	main(void)
{
	{
		//this should block compilation if AAnimal is abstract
		//AAnimal animal;

		//this should block compilation because of object slicing
		// Dog dog;
		// AAnimal *animal = dog;
	}
	LOG_INFO("Starting Polymorphism throigh base pointer test (1/4)...\n");
	{
		AAnimal *jojo = new Dog();
		AAnimal *Miao = new Cat();
		

		jojo->makeSound();
		Miao->makeSound();

		delete jojo;
		delete Miao;
	}
	std::cout << '\n';
	LOG_INFO("Starting Brain basic set/get test (2/4)...\n");
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
	LOG_INFO("Starting Polymorphic array test (3/4)...\n");
	{
		const int	size = 10;
		AAnimal*		animals[size];

		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
				animals[i] = static_cast<AAnimal *>(new Dog());
			else
				animals[i] = static_cast<AAnimal *>(new Cat());
		}

		for (int i = 0; i < size; i++)
			animals[i]->makeSound();

		for (int i = 0; i < size; i++)
			delete animals[i];
	}
	std::cout << '\n';
	LOG_INFO("Starting Deep copy test (4/4)...\n");
	{
		AAnimal* gato = new Cat();
		static_cast<Cat*>(gato)->setIdea(0, "Tuna");

		AAnimal* neko = new Cat(*(static_cast<Cat*>(gato)));

		static_cast<Cat*>(neko)->setIdea(0, "Salmon");

		std::cout << static_cast<Cat*>(neko)->getIdea(0) << std::endl;

		delete gato;
		delete neko;
	}
	std::cout << '\n';
	LOG_SUCCESS("All tests completed.\n");
}
