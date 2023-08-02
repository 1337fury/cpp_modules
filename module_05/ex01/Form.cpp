/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:43:48 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/02 16:44:41 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const &name, int signeGrade, int executeGrade)
    : name(name), isSigned(false), signeGrade(signeGrade), executeGrade(executeGrade)
{
    if (signeGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signeGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &src)
    : name(src.name), isSigned(src.isSigned), signeGrade(src.signeGrade), executeGrade(src.executeGrade)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string const &Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getSignGrade() const
{
    return this->signeGrade;
}

int Form::getExecuteGrade() const
{
    return this->executeGrade;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signeGrade)
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

void	Form::signForm(Bureaucrat& bureaucrat)
{
	if (this->isSigned)
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	else
	{
		std::cout << bureaucrat.getName() << " couldn’t sign  " << this->getName();
		std::cout << " because it does not meet the requirement." << std::endl;
	}
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
    o << "Form Details:" << std::endl
      << "Name: " << i.getName() << std::endl
      << "Is Signed: " << (i.getIsSigned() ? "Yes" : "No") << std::endl
      << "Grade to Sign: " << i.getSignGrade() << std::endl
      << "Grade to Execute: " << i.getExecuteGrade();
    return o;
}

