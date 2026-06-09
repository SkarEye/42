/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 12:11:07 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 14:53:00 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>
# include <ostream>

class	AForm;

class	Bureaucrat
{
	private:
		static const int	GRADE_MAX = 1;
		static const int	GRADE_MIN = 150;
		
		const std::string	_name;
		int					_grade;

		static int	validateGrade(int grade);

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string&	getName() const;
		int					getGrade() const;
		
		int					getMaxGrade();
		int					getMinGrade();

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm &f) const;
		void	executeForm(const AForm &f) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b);

#endif
