/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:35:30 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/30 09:30:28 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("Nano", 2);
        std::cout << b << std::endl;

        b.incrementGrade();
        std::cout << b << std::endl;

        b.decrementGrade();
		std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;

        Bureaucrat c("3edyano", 5);
        std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}