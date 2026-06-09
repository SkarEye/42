/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:51:23 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 15:50:55 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

# include "AForm.hpp"

class	Intern
{
	public:
		Intern(void);
		Intern(const Intern& other);
		~Intern();

		Intern& operator=(const Intern& other);

		AForm*	makeForm(const std::string& name, const std::string& target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif