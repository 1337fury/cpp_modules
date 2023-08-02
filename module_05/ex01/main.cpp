/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:35:30 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/30 17:36:23 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		std::cout << "====================================" << std::endl;

		Form form("42-A", 10, 12);
		std::cout << form << std::endl;
		
		std::cout << "====================================" << std::endl;

		Bureaucrat nano("Chab Nano", 150);
		std::cout << nano << std::endl;
		form.beSigned(nano);
		form.signForm(nano);

		std::cout << "====================================" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << RED << "====================================" << WHITE <<std::endl;

		Form form("HS-202", 3, 4);
		std::cout << form << std::endl;
		
		std::cout << "====================================" << std::endl;

		Bureaucrat lydia("Lydia Moonshadow", 2);
		std::cout << lydia << std::endl;
		form.beSigned(lydia);
		form.signForm(lydia);

		std::cout << "====================================" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << RED << "====================================" << WHITE <<std::endl;

		Form form("ECO-22", 1, 2);
		std::cout << form << std::endl;
		
		std::cout << "====================================" << std::endl;

		Bureaucrat Diana("Diana Greenleaf", 1);
		Diana.incrementGrade();
		std::cout << Diana << std::endl;
		form.beSigned(Diana);
		form.signForm(Diana);

		std::cout << "====================================" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}