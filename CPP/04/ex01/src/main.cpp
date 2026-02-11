/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:44:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/06 13:59:26 by mattcarniel      ###   ########.fr       */
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
	LOG_INFO("Starting polymorphic calls through base class pointers test (1/9)...");
	{
		const Animal*	meta = new Animal();
		const Animal*	volt = new Dog();
		const Animal*	pawz = new Cat();

		LOG_INFO("'meta' type: " + meta->getType());
		meta->makeSound();
		// Calls Animal::makeSound because dynamic type is Animal
		LOG_INFO("'volt' type: " + volt->getType());
		volt->makeSound();
		// Virtual dispatch to Dog::makeSound
		LOG_INFO("'pawz' type: " + pawz->getType());
		pawz->makeSound();
		// Virtual dispatch to Cat::makeSound
		
		delete meta;
		delete volt;
		delete pawz;
	}
	std::cout << '\n';
	LOG_INFO("Starting Concrete class instances test (2/9)...");
	{
		Animal	animal;
		Dog		dog;
		Cat		cat;

		LOG_INFO("'animal' type: " + animal.getType());
		animal.makeSound();
		// Will output Animal sound
		LOG_INFO("'dog' type: " + dog.getType());
		dog.makeSound();
		// Will output Dog sound
		LOG_INFO("'cat' type: " + cat.getType());
		cat.makeSound();
		// Will output Cat sound
	}
	std::cout << '\n';
	LOG_INFO("Starting array of base class pointers test (3/9)...");
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
			LOG_INFO("#" + std::to_string(i) + " type: " + animals[i]->getType());
			animals[i]->makeSound();
		}
		for (size_t i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << '\n';
	LOG_INFO("Starting Animal assignment operator test (4/9)...");
	{
		Animal*	animal1 = new Dog();
		Animal*	animal2 = new Cat();
		*animal1 = *animal2;

		LOG_INFO("'animal1' type after assignment: " + animal1->getType());
		animal1->makeSound();
		// Assignment only copies the Animal subobject (_type).
		// The dynamic type remains Dog, so virtual dispatch still calls Dog::makeSound().

		delete animal1;
		delete animal2;
	}
	std::cout << '\n';
	LOG_INFO("Starting inherited class assignment operator test (5/9)...");
	{
		Cat	cat1;
		Cat	cat2;

		cat1 = cat2;

		LOG_INFO("'cat1' type after assignment: " + cat1.getType());
		cat1.makeSound();
		// Will output Cat sound
	}
	std::cout << '\n';
	LOG_INFO("Starting slicing detection test (6/9)...");
	{
		Cat	cat;
		Animal	animal = cat;
		// Object slicing: only the Animal part is copied, derived behavior is lost

		LOG_INFO("'animal' type after slicing: " + animal.getType());
		animal.makeSound();
	}
	std::cout << '\n';
	LOG_INFO("Starting Copy constructor test (7/9)...");
	{
		Cat	cat1;
		Cat	cat2(cat1);

		LOG_INFO("'cat2' type after copy construction: " + cat2.getType());
		cat2.makeSound(); // Will output Cat sound
	}
	std::cout << '\n';
	LOG_INFO("Starting WrongAnimal polymorphism test (8/9)...");
	{
		const WrongAnimal*	wrongMeta = new WrongAnimal();
		const WrongAnimal*	wrongPawz = new WrongCat();

		LOG_INFO("'wrongMeta' type: " + wrongMeta->getType());
		wrongMeta->makeSound();
		LOG_INFO("'wrongPawz' type: " + wrongPawz->getType());
		wrongPawz->makeSound();
		// makeSound() is not virtual in WrongAnimal,
		// so the base class implementation is called even for WrongCat

		delete wrongMeta;
		delete wrongPawz;
	}
	std::cout << '\n';
	LOG_INFO("Starting self-assignment test... (9/9)");
	{
		Dog	dog;
		Dog	&ref = dog;

		ref = dog;	
		LOG_INFO("'dog' type after self-assignment: " + ref.getType());
		ref.makeSound();
		// Self-assignment should be safely handled by operator= (no state corruption)

	}
	std::cout << '\n';
	LOG_SUCCESS("All tests completed.");
	return (0);
}
