/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:51:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 13:52:15 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") 
{
	std::cout << "New "<< RED << "WrongAnimal" << RESET " Created. Weclome!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal& copy)
{
	std::cout << RED << "WrongAnimal" << RESET " copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other)
{
	std::cout << RED << "WrongAnimal" << RESET " assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "WrongAnimal" << RESET " Destroyed. bye!" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Unknown WrongAnimal sound!" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
