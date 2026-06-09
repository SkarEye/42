/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mattcarniel <mattcarniel@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:24:24 by mattcarniel       #+#    #+#             */
/*   Updated: 2026/05/15 15:53:47 by mattcarniel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <exception>
# include <ostream>

class	Bureaucrat;

class	AForm
{
	private:
		static const int	GRADE_MAX = 1;
		static const int	GRADE_MIN = 150;
		
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;

		static int	validateGrade(int grade);

	public:
		AForm(void);
		AForm(const std::string& name, int sign_grade, int exec_grade);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		const std::string&	getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		int					getMaxGrade();
		int					getMinGrade();

		void			beSigned(const Bureaucrat& b);

		virtual	void	execute(const Bureaucrat& e) const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
