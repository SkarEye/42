/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:15:40 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/01/05 19:12:30 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal&			operator=(const Animal& other);

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif