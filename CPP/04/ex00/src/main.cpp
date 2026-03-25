/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/26 12:02:52 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include "Ansi.hpp"

int	main(void)
{
	LOG_INFO("Starting polymorphic calls through base class pointers test (1/9)...\n");
	{
		const Animal*	meta = new Animal();
		const Animal*	volt = new Dog();
		const Animal*	pawz = new Cat();

		std::cout << "'meta' type: " << meta->getType() << '\n';
		meta->makeSound();
		// Calls Animal::makeSound because dynamic type is Animal
		std::cout << "'volt' type: " + volt->getType() << '\n';
		volt->makeSound();
		// Virtual dispatch to Dog::makeSound
		std::cout << "'pawz' type: " + pawz->getType() << '\n';
		pawz->makeSound();
		// Virtual dispatch to Cat::makeSound
		
		delete meta;
		delete volt;
		delete pawz;
	}
	std::cout << '\n';
	LOG_INFO("Starting Concrete class instances test (2/9)...\n");
	{
		Animal	animal;
		Dog		dog;
		Cat		cat;

		std::cout << "'animal' type: " + animal.getType() << '\n';
		animal.makeSound();
		// Will output Animal sound
		std::cout << "'dog' type: " + dog.getType() << '\n';
		dog.makeSound();
		// Will output Dog sound
		std::cout << "'cat' type: " + cat.getType() << '\n';
		cat.makeSound();
		// Will output Cat sound
	}
	std::cout << '\n';
	LOG_INFO("Starting array of base class pointers test (3/9)...\n");
	{
		const Animal*	animals[4];
		for (size_t i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		for (size_t i = 0; i < 4; i++)
		{
			std::cout << "#" + std::to_string(i) + " type: " + animals[i]->getType() << '\n';
			animals[i]->makeSound();
		}
		for (size_t i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << '\n';
	LOG_INFO("Starting Animal assignment operator test (4/9)...\n");
	{
		Animal*	animal1 = new Dog();
		Animal*	animal2 = new Cat();
		*animal1 = *animal2;

		std::cout << "'animal1' type after assignment: " + animal1->getType() << '\n';
		animal1->makeSound();
		// Assignment only copies the Animal subobject (_type).
		// The dynamic type remains Dog, so virtual dispatch still calls Dog::makeSound().

		delete animal1;
		delete animal2;
	}
	std::cout << '\n';
	LOG_INFO("Starting inherited class assignment operator test (5/9)...\n");
	{
		Cat	cat1;
		Cat	cat2;

		cat1 = cat2;

		std::cout << "'cat1' type after assignment: " + cat1.getType() << '\n';
		cat1.makeSound();
		// Will output Cat sound
	}
	std::cout << '\n';
	LOG_INFO("Starting slicing detection test (6/9)..\n");
	{
		Cat	cat;
		Animal	animal = cat;
		// Object slicing: only the Animal part is copied, derived behavior is lost

		std::cout << "'animal' type after slicing: " + animal.getType() << '\n';
		animal.makeSound();
	}
	std::cout << '\n';
	LOG_INFO("Starting Copy constructor test (7/9)...\n");
	{
		Cat	cat1;
		Cat	cat2(cat1);

		std::cout << "'cat2' type after copy construction: " + cat2.getType() << '\n';
		cat2.makeSound();
		// Will output Cat sound
	}
	std::cout << '\n';
	LOG_INFO("Starting WrongAnimal polymorphism test (8/9)...\n");
	{
		const WrongAnimal*	wrongMeta = new WrongAnimal();
		const WrongAnimal*	wrongPawz = new WrongCat();

		std::cout << "'wrongMeta' type: " + wrongMeta->getType() << '\n';
		wrongMeta->makeSound();
		std::cout << "'wrongPawz' type: " + wrongPawz->getType() << '\n';
		wrongPawz->makeSound();
		// makeSound() is not virtual in WrongAnimal,
		// so the base class implementation is called even for WrongCat

		delete wrongMeta;
		delete wrongPawz;
	}
	std::cout << '\n';
	LOG_INFO("Starting self-assignment test (9/9)...\n");
	{
		Dog	dog;
		Dog	&ref = dog;

		ref = dog;	
		std::cout << "'dog' type after self-assignment: " + ref.getType() << '\n';
		ref.makeSound();
		// Self-assignment should be safely handled by operator= (no state corruption)

	}
	std::cout << '\n';
	LOG_SUCCESS("All tests completed.\n");
	return (0);
}
