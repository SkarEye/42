/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:06:57 by mattcarniel       #+#    #+#             */
/*   Updated: 2025/12/09 16:04:42 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string& level);
};

typedef struct s_HarlFn
{
	std::string	name;
	void		(Harl::*func)();
}	t_HarlFn;

#endif