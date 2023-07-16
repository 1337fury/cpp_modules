/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:54:28 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/12 13:41:41 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		newHarl;
	std::string level;

	if (ac != 2)
		return (std::cerr << RED << USAGE << RESET << std::endl, 1);
	level = av[1];
	newHarl.complain(level);
}
