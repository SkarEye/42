/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/14 12:36:05 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <exception>
# include <ostream>

class	Bureaucrat;

class	Form
{
	private:
		static const int	GRADE_MAX = 1;
		static const int	GRADE_MIN = 150;
		
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;

	int	validateGrade(int grade);

	public:
		Form(void);
		Form(const std::string& name, int sign_grade, int exec_grade);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		int					getMaxGrade();
		int					getMinGrade();

		void	beSigned(const Bureaucrat& b);

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

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
