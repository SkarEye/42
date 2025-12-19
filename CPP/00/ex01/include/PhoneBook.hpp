/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:47:51 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/06 11:26:23 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

typedef enum e_instruction
{
	I_EXIT = 0,
	I_ERROR = 1,
	I_ADD,
	I_SEARCH,
	I_COUNT
}	t_instruction;

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_index;
		bool	_isFull;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact(void);
		void	printContact(void) const;

		void	_debugPrint(void) const;
};

#endif
