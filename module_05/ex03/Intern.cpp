/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:45:49 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/03 13:30:01 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    // Default constructor implementation
}

Intern::Intern(const Intern& other)
{
	*this = other;
    // Copy constructor implementation
}
Intern& Intern::operator=(const Intern& other)
{
    if (this == &other)
	{
        return *this;
    }
     // Copy assignment operator implementation
     return *this;
}
Intern::~Intern()
{
    // Destructor implementation
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	if (formName == "robotomy request")
	{
		std::cout << "Intern creates robotomy request" << std::endl;
		return new RobotomyRequestForm(formTarget);
	}
	else if (formName == "Shrubbery creation")
	{
		std::cout << "Intern creates shrubbery creation" << std::endl;
		return new ShrubberyCreationForm(formTarget);
	}
	else if (formName == "Presidential pardon")
	{
		std::cout << "Intern creates presidential pardon" << std::endl;
		return new PresidentialPardonForm(formTarget);
	}
	else 
	{
        std::cout << "Error: Invalid form name" << std::endl;
        return (NULL);
    }
}
