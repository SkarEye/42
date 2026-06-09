/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:58:51 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/19 15:21:08 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class	Base
{
	public:
		virtual	~Base();
};

class	A: public Base {};
class	B: public Base {};
class	C: public Base {};

Base*	generate(void);

void	identify(Base* p);
void	identify(Base& r);

#endif