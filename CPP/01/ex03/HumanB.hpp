/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:15:06 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:02:11 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>

# include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon*		weapon;

	public:
		HumanB(std::string name);

		void	setWeapon(Weapon& weapon);
		void	attack(void);
};

#endif