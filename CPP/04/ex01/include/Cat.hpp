/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:30:21 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/02/23 14:53:07 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_brain;
	public:
		Cat(void);
		Cat(const Cat& other);
		virtual ~Cat();

		Cat&			operator=(const Cat& other);

		virtual void	makeSound() const;
		void			setIdea(int const index, const std::string &idea);
		std::string		getIdea(int const index) const;
};

#endif