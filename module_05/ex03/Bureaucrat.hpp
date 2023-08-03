/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:42:29 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/02 16:51:18 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &);
		~Bureaucrat();

		Bureaucrat & operator=(const Bureaucrat &);

		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooHighException : public std::exception {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            const char* what() const throw();
        };

		void	executeForm(AForm const & form);

	private:
		Bureaucrat( void );

		const std::string 	name;
		int					grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);
