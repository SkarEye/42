/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:32:18 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/03/25 16:59:55 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ICharacter.hpp"

#include "../include/Ansi.hpp"

ICharacter::~ICharacter()
{
	LOG_DEBUG("[ICharacter] destructor called");
}