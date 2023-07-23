/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:21:20 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 13:55:53 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "Cat";
	std::cout << "New " << RED << "Cat" << RESET <<" Created. Weclome!" << std::endl;
}

Cat::Cat(Cat& copy)
{
	std::cout << RED << "Cat" << RESET <<" copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

Cat& Cat::operator=(Cat& other)
{
	std::cout << RED << "Cat" << RESET << " assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
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