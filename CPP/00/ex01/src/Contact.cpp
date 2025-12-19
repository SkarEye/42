/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:58:04 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/06 11:58:25 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "../include/Contact.hpp"
#include "../include/ansi.hpp"

std::string	Contact::label[] =
{
	"First Name",
	"Last Name",
	"Nickname",
	"Phone Number",
	"Darkest Secret",
	"Index"
};

Contact::Contact(void)
{
	for (int i = FIELD_FIRST_NAME; i <= FIELD_DARKEST_SECRET; i++)
		this->field[i] = "";
}

Contact::~Contact(void)
{
}
void	Contact::clearInfo(void)
{
	for (int i = FIELD_FIRST_NAME; i <= FIELD_DARKEST_SECRET; i++)
		this->field[i] = "";
}

bool	Contact::setInfo(void)
{
	int attempts;
	for (int i = FIELD_FIRST_NAME; i <= FIELD_DARKEST_SECRET; i++)
	{
		attempts = 0;
		while (true)
		{
			print_message("ENTER", (Contact::label[i] + ": ").c_str(), false);
			std::getline(std::cin, this->field[i]);
			if (std::cin.eof())
			{
				std::cout << std::endl;
				print_warning("End of input detected. Exiting...", true);
				std::exit(EXIT_SUCCESS);
			}
			if (Contact::field[i].empty())
			{
				print_error("This field cannot be empty.", true);
				attempts++;
			}
			else
				break ;
			if (attempts >= 3)
			{
				print_warning("Maximum attempts reached. Contact creation cancelled.", true);
				clearInfo();
				return (false);
			}
		}
	}
	print_success("Contact added successfully.", true);
	return (true);
}

std::string	Contact::getField(int f) const
{
	if (f < FIELD_FIRST_NAME || f >= FIELD_COUNT)
		return (NULL);
	return (this->field[f]);
}