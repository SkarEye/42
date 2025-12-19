/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:21:46 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/10 10:30:26 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*shaun ;
	
	LOG_INFO("Putting a Zombie on the heap...");
	shaun = newZombie("Shaun");
	shaun->announce();
	delete shaun;

	LOG_INFO("Putting a Zombie on the stack...");
	randomChump("Ed");
}
