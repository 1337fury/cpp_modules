/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:14:30 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/02 22:46:27 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "New "<< RED << "Brain" << RESET " Created. Weclome!" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << RED << "Brain" << RESET " copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << RED << "Brain" << RESET " assignment operator called!" << std::endl;
	if (this != &other)
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << RED << "Brain" << RESET " Destroyed. bye!" << std::endl;
}
