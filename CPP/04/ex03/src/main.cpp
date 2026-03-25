/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 16:52:30 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 18:51:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/IMateriaSource.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/ICharacter.hpp"
#include "../include/Character.hpp"
#include "../include/Ansi.hpp"

#include <iostream>

int main(void)
{
	LOG_INFO("Basic test (1/14)...\n");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << '\n';
	
	LOG_INFO("Invalid indexation test (2/14)...\n");
	{
		ICharacter* c = new Character("test");

		c->use(-1, *c);	// negative index
		c->use(4, *c);	// out of bounds
		c->use(100, *c);	// way out of bounds
		c->use(0, *c);	// empty slot
		c->unequip(-1);			// negative
		c->unequip(4);				// out of bounds
		c->unequip(0);				// empty slot

		delete c;
	}
	std::cout << '\n';

	LOG_INFO("NULL assignment test (3/14)...\n");
	{
		Character c("nulltest");

		c.equip(NULL);
		c.use(0, c);
	}
	std::cout << '\n';

	LOG_INFO("Saturated inventory test (4/14)...\n");
	{
		Character c("full");

		c.equip(new Ice());
		c.equip(new Ice());
		c.equip(new Cure());
		c.equip(new Cure());

		AMateria* extra = new Ice();
		c.equip(extra);
		// extra was NOT equipped — we must delete it ourselves
		delete extra;

		for (int i = 0; i < 4; i++)
			c.use(i, c);
	}
	std::cout << '\n';

	LOG_INFO("Unequip and re-equip test (5/14)...\n");
	{
		Character c("unequip");

		c.equip(new Ice());
		c.equip(new Cure());
		c.use(0, c);

		c.unequip(0);
		c.use(0, c);

		c.equip(new Cure());			
		c.use(0, c);
	}
	std::cout << '\n';

	LOG_INFO("Deep copy constructor test (6/14)...\n");
	{
		Character* original = new Character("original");
		original->equip(new Ice());
		original->equip(new Cure());

		Character* copy = new Character(*original);

		// Delete original — copy should still work
		delete original;

		std::cout << "  Copy name: " << copy->getName() << '\n';
		copy->use(0, *copy);
		copy->use(1, *copy);

		delete copy;
	}
	std::cout << '\n';
	
	LOG_INFO("7. Assignment operator test (7/14)...\n");
	{
		Character a("alpha");
		a.equip(new Ice());
		a.equip(new Cure());

		Character b("beta");
		b.equip(new Ice());

		b = a;

		std::cout << "  b name after assign: " << b.getName() << '\n';
		b.use(0, b);
		b.use(1, b);

		// Modify a — should NOT affect b (deep copy)
		a.unequip(0);
		a.unequip(1);
		b.use(0, b);
		b.use(1, b);
	}
	std::cout << '\n';

	LOG_INFO("Self-assignment test (8/14)...\n");
	{
		Character c("self");
		Character& ref = c;
		c.equip(new Ice());

		c = ref;

		c.use(0, c);
	}
	std::cout << '\n';

	LOG_INFO("MateriaSource copy test (9/14)...\n");
	{
		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		MateriaSource* copy = new MateriaSource(*src);
		delete src;

		AMateria* m = copy->createMateria("ice");
		std::cout << "  Created from copy: " << m->getType() << '\n';
		delete m;

		m = copy->createMateria("cure");
		std::cout << "  Created from copy: " << m->getType() << '\n';
		delete m;

		delete copy;
	}
	std::cout << '\n';

	LOG_INFO("Unknown materia type test (10/14)...\n");
	{
		MateriaSource src;
		src.learnMateria(new Ice());

		AMateria* m = src.createMateria("fire");
		if (m == NULL)
			std::cout << "  createMateria(\"fire\") returned NULL — correct!\n";
		else
		{
			std::cout << "  ERROR: should have returned NULL\n";
			delete m;
		}
	}
	std::cout << '\n';

	LOG_INFO("Saturated MateriaSource test (11/14)...\n");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
	}
	std::cout << '\n';

	LOG_INFO("Polymorphism test (12/14)...\n");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		ICharacter* c = new Character("poly");
		AMateria* m = src->createMateria("ice");

		c->equip(m);
		c->use(0, *c);

		std::cout << "  Type through AMateria*: " << m->getType() << '\n';

		delete c;
		delete src;
	}
	std::cout << '\n';

	LOG_INFO("Unequip/re-equip cycle test (13/14)...\n");
	{
		Character c("cycle");

		for (int i = 0; i < 1025; i++)
		{
			c.equip(new Ice());
			c.unequip(0);
		}
	}
	std::cout << '\n';

	LOG_INFO("Clone independence test (14/14)...\n");
	{
		AMateria* ice = new Ice();
		AMateria* clone = ice->clone();

		std::cout << "  Original: " << ice->getType() << '\n';
		std::cout << "  Clone:    " << clone->getType() << '\n';

		delete ice;
		// clone should still be valid
		std::cout << "  Clone after delete: " << clone->getType() << '\n';

		delete clone;
	}
	std::cout << '\n';

	LOG_SUCCESS("All tests completed.\n");
	return (0);
}