/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:15:06 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/08 22:02:07 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon&		weapon;

	public:
		HumanA(std::string name, Weapon& weapon);

		void	attack(void);
};

#endif