/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:05:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/19 12:10:11 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return std::cerr << RED << USAGE << std::endl, 1;

	try
	{
		RPN	rpn(av[1]);
		rpn.result();
		return (EXIT_SUCCESS);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}


