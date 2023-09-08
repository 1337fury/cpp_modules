/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:35:30 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/08 16:17:01 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm* robotomy = intern.makeForm("robotomy request", "Bender");
	AForm* shrubbery = intern.makeForm("Shrubbery creation", "Argan");
	AForm* Presidential = intern.makeForm("Presidential pardon", "victim");
	
	AForm* none = intern.makeForm("none", "none");


	std::cout << *robotomy << std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << *Presidential << std::endl;

	delete robotomy;
	delete shrubbery;
	delete Presidential;
	delete none;
	return (0);
}
