/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 13:49:20 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") 
{
	std::cout << "New "<< RED << "Animal" << RESET " Created. Weclome!" << std::endl;
}

Animal::Animal(Animal& copy)
{
	std::cout << RED << "Animal" << RESET " copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

Animal& Animal::operator=(Animal& other)
{
	std::cout << RED << "Animal" << RESET " assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal" << RESET " Destroyed. bye!" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Unknown Animal sound!" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}