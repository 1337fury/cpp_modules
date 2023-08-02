/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:53:50 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/02 16:52:23 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
     if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) 
{
    if (this != &other)
        this->grade = other.grade;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

void		Bureaucrat::incrementGrade()
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooHighException();
	else
		grade++;
}

void	Bureaucrat::decrementGrade()
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooLowException();
	else
		grade--;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade too low!");
}

std::ostream &operator<<(std::ostream& o, Bureaucrat const &i)
{
	o << i.getName() << " bureaucrat grade " << i.getGrade();
	return (o);
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
        form.execute(*this);
    }
	catch (const std::exception& e) {
        std::cout << "(" << *this << ") could't execute (" << form << ") because (" << e.what() << ")" << std::endl;
        return;
    }
    std::cout << "(" << *this << ") executed (" << form << ")" << std::endl;
}
