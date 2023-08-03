/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:35:30 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/03 16:49:12 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try
	{

		Bureaucrat hamza("hamza", 60); //Bureaucrat
		
		std::cout << "\n\t\t[Bureaucrat]" << std::endl;
		std::cout << hamza << std::endl;

		ShrubberyCreationForm sForm("2A-00"); //Form

		std::cout << "\n\t\t[Form(before)]" << std::endl;
		std::cout << sForm << std::endl;

		sForm.beSigned(hamza); //try sign form

		std::cout << "\n\t\t[Form(after)]" << std::endl;
		std::cout << sForm << std::endl;

		sForm.execute(hamza); //try execute form
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{

		Bureaucrat Moad("Moad", 150); //Bureaucrat
		
		std::cout << "\n\t\t[Bureaucrat]" << std::endl;
		std::cout << Moad << std::endl;

		ShrubberyCreationForm xForm("XXXX"); //Form

		std::cout << "\n\t\t[Form(before)]" << std::endl;
		std::cout << xForm << std::endl;

		xForm.beSigned(Moad); //try sign form

		std::cout << "\n\t\t[Form(after)]" << std::endl;
		std::cout << xForm << std::endl;

		xForm.execute(Moad); //try execute form
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
