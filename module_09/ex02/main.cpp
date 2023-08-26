/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:14:58 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/25 22:27:27 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cerr << "Error: No positive integer sequence provided." << std::endl;
        return 1;
	}
	try
	{
		PmergeMe	arguments(av, ac);
		arguments.mergeMe();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}