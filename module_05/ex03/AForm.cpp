/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:18:29 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/30 22:10:03 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const &name, int signeGrade, int executeGrade)
    : name(name), isSigned(false), signeGrade(signeGrade), executeGrade(executeGrade)
{
    if (signeGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signeGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src)
    : name(src.name), isSigned(src.isSigned), signeGrade(src.signeGrade), executeGrade(src.executeGrade)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &other)
{
    if (this != &other)
    {
        this->isSigned = other.isSigned;
    }
    return *this;
}

std::string const &AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->signeGrade;
}

int AForm::getGradeToExecute() const
{
    return this->executeGrade;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->signeGrade)
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::signForm(Bureaucrat& bureaucrat)
{
	if (this->isSigned)
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	else
	{
		std::cout << bureaucrat.getName() << " couldn’t sign  " << this->getName();
		std::cout << " because it does not meet the requirement." << std::endl;
	}
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "AForm::GradeTooHighException";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException";
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
    o << "AForm Details:" << std::endl
      << "Name: " << i.getName() << std::endl
      << "Is Signed: " << (i.getIsSigned() ? "Yes" : "No") << std::endl
      << "Grade to Sign: " << i.getGradeToSign() << std::endl
      << "Grade to Execute: " << i.getGradeToExecute();
    return o;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();

    if (executor.getGrade() > this->executeGrade)
        throw GradeTooLowException();
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Does not meet the requirement to execute!");
}

