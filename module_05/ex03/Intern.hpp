/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:37:52 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/08 16:03:01 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(); // Default constructor
		Intern(const Intern& other); // Copy constructor
		Intern& operator=(const Intern& other); // Copy assignment operator
		~Intern(); // Destructor

		AForm* makeForm(const std::string& name, const std::string& target);

		AForm*	robotomy( const std::string& );
		AForm*	shrubbery( const std::string& );
		AForm*	presidential( const std::string& );

	private:
		
};

typedef	AForm* (Intern::*robotomyPtr)( const std::string& );
typedef	AForm* (Intern::*shrubberyPtr)( const std::string& );
typedef	AForm* (Intern::*presidentialPtr)( const std::string& );

typedef AForm* (Intern::*allForm[3]) ( const std::string& );

#endif // INTERN_HPP