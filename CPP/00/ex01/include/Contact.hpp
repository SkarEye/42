/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:50:30 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/06 11:57:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string			field[5];

	public:
		enum e_field
		{
			FIELD_FIRST_NAME = 0,
			FIELD_LAST_NAME,
			FIELD_NICKNAME,
			FIELD_PHONE_NUMBER,
			FIELD_DARKEST_SECRET,
			FIELD_INDEX,
			FIELD_COUNT
		};
		
		static std::string	label[]; //might not be allowed

		Contact(void);
		~Contact(void);

		void		clearInfo(void);
		bool		setInfo(void);
		std::string getField(int f) const;
};

#endif
