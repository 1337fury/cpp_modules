/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:23 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/04 17:51:06 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "Dog";
	try
	{
		brain = new Brain();
	}
	catch(const std::bad_exception& e)
	{
		brain = NULL;
		std::cerr << e.what() << '\n';
	}
	std::cout << "New " << RED << "Dog" << RESET << " Created. Weclome!" << std::endl;
}

Dog::Dog(const Dog& copy)
{
	std::cout << RED << "Dog" << RESET << " copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << RED << "Dog" << RESET << " assignment operator called!" << std::endl;
	if (this != &other)
	{
		//deep copy
		delete brain;
		this->brain = new Brain(*other.brain);
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
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
