/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:34:33 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/30 19:13:38 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"


//  Define color codes
#define RED  "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE  "\033[0;97m"

class Bureaucrat;  // Forward declaration of Bureaucrat class to avoid circular dependency

class Form
{
	public:
		Form(std::string const &name, int signeGrade, int executeGrade);
		virtual ~Form();

		Form(const Form &src);
		Form &operator=(const Form &other);

		class GradeTooHighException : public std::exception {
			char const *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			char const *what() const throw();
		};

		// Getters
		const std::string 	&getName() const;
		int 				getSignGrade() const;
		int 				getExecuteGrade() const;
		bool 				getIsSigned() const;

		//Other
		void	beSigned(Bureaucrat& bureaucrat);
		void	signForm(Bureaucrat& bureaucrat);

	private:
		// Private default constructor to prevent creating a form without enough information
    	Form();

		const std::string 	name;
		bool				isSigned;
		const int			signeGrade;
		const int			executeGrade;
};

std::ostream& operator<<(std::ostream& o, const Form &form);
