/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:20 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/03 17:07:34 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	try
	{
		brain = new Brain();
	}
	catch(const std::bad_exception& e)
	{
		std::cerr << e.what() << std::endl;
		brain = NULL;
	}
	std::cout << "New " << RED << "Cat" << RESET <<" Created. Weclome!" << std::endl;
}

Cat::Cat(const Cat& copy)
{
	std::cout << RED << "Cat" << RESET <<" copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << RED << "Cat" << RESET << " assignment operator called!" << std::endl;
	if (this != &other)
	{
		//deep copy
		delete this->brain;
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << RED << "Cat" << RESET <<" Destroyed. bye!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meaw!" << std::endl;
}

std::string	Cat::getType() const
{
	return (this->type);
}
