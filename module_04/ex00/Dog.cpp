/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:23 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 13:55:32 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "New " << RED << "Dog" << RESET << " Created. Weclome!" << std::endl;
}

Dog::Dog(Dog& copy)
{
	std::cout << RED << "Dog" << RESET << " copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

Dog& Dog::operator=(Dog& other)
{
	std::cout << RED << "Dog" << RESET << " assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog" << RESET << " Destroyed. bye!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return (this->type);
}
