/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:45:49 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/08 16:08:35 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

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

AForm*	Intern::robotomy( const std::string& formTarget )
{
	std::cout << "Intern creates robotomy request" << std::endl;
	return new RobotomyRequestForm(formTarget);
}

AForm*	Intern::shrubbery( const std::string& formTarget )
{
	std::cout << "Intern creates shrubbery creation" << std::endl;
	return new ShrubberyCreationForm(formTarget);
}

AForm*	Intern::presidential( const std::string& formTarget )
{
	std::cout << "Intern creates presidential pardon" << std::endl;
	return new PresidentialPardonForm(formTarget);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	robotomyPtr		robo = &Intern::robotomy;
	shrubberyPtr 	shru = &Intern::shrubbery;
	presidentialPtr	pres = &Intern::presidential;

	allForm			all = {robo, shru, pres};
	std::string 	request[3] = {"robotomy request", "Shrubbery creation", "Presidential pardon"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == request[i])
			return ((this->*all[i])(formTarget));
	}
	std::cout << "Error: Invalid form name" << std::endl;
    return (NULL);
}
