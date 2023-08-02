/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:28:12 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/23 18:44:26 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
ClapTrap("default_clap_name"),
FragTrap(),
ScavTrap(),
name("default")
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap named " << name << " default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) :
ClapTrap(name + "_clap_name"),
FragTrap(name),
ScavTrap(name),
name(name)
{
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap named " << name << " constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) :
ClapTrap(copy),
FragTrap(copy),
ScavTrap(copy)
{
	operator=(copy);
	std::cout << "DiamondTrap named " << name << " copy constructor called!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap named " << name << " copy assignment operator called!" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap named " << name << " destructor called!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->name << " and my ClaptTrap name is " << this->ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}