/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:58:10 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/06 12:06:19 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "../include/PhoneBook.hpp"
#include "../include/ansi.hpp"

static t_instruction	get_instruction(void)
{
	std::string	input;
	int			attempts = 0;

	while (attempts < 3)
	{
		print_message("ENTER INSTRUCTION", "(ADD, SEARCH, EXIT): ", false);
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			print_warning("End of input detected. Exiting...", true);
			std::exit(EXIT_FAILURE);
		}
		if (input == "ADD" || input == "add")
			return (I_ADD);
		else if (input == "SEARCH" || input == "search")
			return (I_SEARCH);
		else if (input == "EXIT" || input == "exit")
		{
			print_info("Exiting the program. Goodbye!", true);
			std::exit(EXIT_SUCCESS);
		}
		else
		{
			print_error("Invalid command. Please type 'ADD, 'SEARCH' or 'EXIT.", true);
			attempts++;
		}
	}
	print_warning("Maximum attempts reached. Exiting the program.", true);
	std::exit(EXIT_FAILURE);
}

int	main(void)
{
	PhoneBook	phoneBook;
	t_instruction	instruction;

	print_message("PhoneBook 1.0", "Because what the flip is a smartphone?", true);
	while (true)
	{
		#if DEBUG
			phoneBook._debugPrint();
		#endif
		instruction = get_instruction();
		if (instruction == I_ADD)
			phoneBook.addContact();
		else if (instruction == I_SEARCH)
			phoneBook.printContact();
	}
	return (0);
}
