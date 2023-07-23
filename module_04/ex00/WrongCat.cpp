/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:53:46 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 13:53:48 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "New " << RED << "WrongCat" << RESET <<" Created. Weclome!" << std::endl;
}

WrongCat::WrongCat(WrongCat& copy)
{
	std::cout << RED << "WrongCat" << RESET <<" copy operation was completed successfuly" << std::endl;
	operator=(copy);
}

WrongCat& WrongCat::operator=(WrongCat& other)
{
	std::cout << RED << "WrongCat" << RESET << " assignment operator called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat" << RESET <<" Destroyed. bye!" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meaw!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return (this->type);
}
