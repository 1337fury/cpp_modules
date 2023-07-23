/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 12:14:45 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/20 13:07:33 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice& copy) : AMateria(copy)
{
	operator=(copy);
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Ice* Ice::clone() const
{
	Ice*	ice = NULL;
	try
	{
		ice = new Ice(*this);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return (ice);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
