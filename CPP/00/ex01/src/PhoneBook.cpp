/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:58:12 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/06 12:32:25 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "../include/PhoneBook.hpp"
#include "../include/ansi.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_isFull = false;
}

PhoneBook::~PhoneBook(void)
{
}

static void	print_divider(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

static void	print_wall(void)
{
	std::cout << "|";
}

static void	print_column(const std::string &str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}

static void print_header()
{
	print_divider();
	print_wall();
	print_column(Contact::label[Contact::FIELD_INDEX]);
	for (int i = Contact::FIELD_FIRST_NAME; i <= Contact::FIELD_NICKNAME; i++)
	{
		print_wall();
		print_column(Contact::label[i]);
	}
	print_wall();
	print_nl();
	print_divider();
}

static bool proceed(void)
{
	std::string	input;
	int			attempts = 0;

	while (attempts < 3)
	{
		print_message("Do you want to proceed?", "(y/n): ", false);
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			print_warning("End of input detected. Exiting...", true);
			std::exit(EXIT_SUCCESS);
		}
		if (input == "y" || input == "Y")
			return (true);
		else if (input == "n" || input == "N")
			return (false);
		else
		{
			print_error("Invalid input. Please enter 'y' or 'n'.", true);
			attempts++;
		}
	}
	print_warning("Maximum attempts reached. Operation cancelled.", true);
	return (false);
}

static int get_index(int limit)
{
	std::string	input;
	int			index;
	int			attempts = 0;

	while (attempts < 3)
	{
		print_message("ENTER", "Contact index to view: ", false);
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			print_warning("End of input detected. Exiting...", true);
			std::exit(EXIT_FAILURE);
		}
		try
		{
			index = std::stoi(input);
			if (index >= 1 && index <= limit)
				return (index);
			else
				throw std::out_of_range("Index out of range");
		}
		catch (const std::exception &e)
		{
			print_error("Invalid index. Please enter a valid value.", true);
			attempts++;
		}
	}
	print_warning("Maximum attempts reached. Operation cancelled.", true);
	return (-1);
}

void	PhoneBook::addContact(void)
{
	if (this->_isFull == true)
	{
		print_warning("PhoneBook is full. The oldest contact will be overwritten.", true);
		if (proceed() == false)
			return ;
		this->_contacts[0].clearInfo();
		for (int i = 1; i < 8; i++)
			this->_contacts[i - 1] = this->_contacts[i];
		this->_index = 7;
		this->_isFull = false;
		print_success("Oldest contact removed. You can now add a new contact.", true);
	}
	print_info ("Adding a new contact...", true);
	if (this->_contacts[this->_index].setInfo() == true)
	{
		this->_index++;
		if (this->_index >= 8)
		{
			print_warning("PhoneBook is now full. New contacts will overwrite the oldest ones.", true);
			this->_index = 0;
			this->_isFull = true;
		}
	}
}

void	PhoneBook::printContact(void) const
{
	int	index;
	int	limit;

	if (this->_index == 0 && this->_isFull == false)
	{
		print_warning("PhoneBook is empty. Please add contacts first.", true);
		return ;
	}
	limit = this->_isFull ? 8 : this->_index;
	print_header();
	for (int i = 0; i < limit; i++)
	{
		print_wall();
		print_column(std::to_string(i + 1));
		for (int j = Contact::FIELD_FIRST_NAME; j <= Contact::FIELD_NICKNAME; j++)
		{
			print_wall();
			print_column(this->_contacts[i].getField(j));
		}
		print_wall();
		print_nl();
	}
	print_divider();
	index = get_index(limit);
	if (index == -1)
		return ;
	print_info("Displaying contact details:", true);
	for (int i = Contact::FIELD_FIRST_NAME; i <= Contact::FIELD_DARKEST_SECRET; i++)
	{
		std::cout	<< ANSI_BOLD
					<< std::left
					<< std::setw(15)
					<< Contact::label[i]
					<< ": "
					<<  ANSI_RESET;
		if (i == Contact::FIELD_DARKEST_SECRET)
			std::cout << ANSI_BLACK ANSI_ITALIC;
		std::cout	<< this->_contacts[index - 1].getField(i)
					<< ANSI_RESET
					<< std::endl;
	}
}

void	PhoneBook::_debugPrint(void) const
{
	print_debug("PhoneBook Debug Info:", true);
	print_debug(("Current Index: " + std::to_string(this->_index)).c_str(), true);
	print_debug(("Is Full: " + std::to_string(this->_isFull)).c_str(), true);
	for (int i = 0; i < 8; i++)
	{
		print_nl();
		print_debug(("Contact " + std::to_string(i + 1) + ":").c_str(), true);
		for (int j = Contact::FIELD_FIRST_NAME; j <= Contact::FIELD_DARKEST_SECRET; j++)
		{
			print_debug((Contact::label[j] + ": " + this->_contacts[i].getField(j)).c_str(), true);
		}
	}
}
