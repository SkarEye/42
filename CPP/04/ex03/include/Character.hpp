/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:49:34 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 15:56:40 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>

#include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	protected:
		std::string	_name;
		AMateria* 	_inventory[4];
		AMateria*	_floor[1024];
		int			_floorCount;
	public:
		Character(void);
		Character(std::string const & name);
		Character(const Character& other);
		virtual ~Character();

		Character& operator=(const Character& other);

		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif