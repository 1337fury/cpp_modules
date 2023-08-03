/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:08:02 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/03 09:31:49 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const &name, int signeGrade, int executeGrade);
        virtual ~AForm();
        
        AForm(AForm const &src); // Copy constructor
        AForm &operator=(AForm const &other); // Assignment operator
        
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
		
		// Getters
        std::string const 	&getName() const;
        bool 				getIsSigned() const;
        int 				getGradeToSign() const;
        int 				getGradeToExecute() const;

		//Other
        void 	beSigned(Bureaucrat& bureaucrat);
		void	signForm(Bureaucrat& bureaucrat);


        class FormNotSignedException : public std::exception
        {
            const char* what() const throw();
        };

        // Pure Virtual Function makes this class Abstract Class
        virtual void execute(Bureaucrat const & executor) const = 0;
	
	private:
        // Made private to prevent default construction
        AForm();

        std::string const 	name;
        bool 				isSigned;
        int const 			signeGrade;
        int const 			executeGrade;
};

std::ostream &operator<<(std::ostream &out, AForm const &rhs);

#endif
