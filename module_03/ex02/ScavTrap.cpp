/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:48:55 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/16 19:42:35 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Default Constructor Called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap Constructor Called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout << "ScavTrap copy constructor called !" << std::endl;
	operator=(copy);
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
	{
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
    std::cout << "ScavTrap copy assignment operator called !" << std::endl;
    return (*this);
}

void	ScavTrap::attack( const std::string& target )
{
	if (energyPoints >= 1 && hitPoints >= 1) 
	{
		energyPoints -= 1;
		std::cout << "ScavTrap " << RED << name << RESET << " attacks " << GREEN << target << RESET << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << name << " doesn't have enough energy to attack!" << std::endl;
	}
}

void ScavTrap::guardGate() 
{
    std::cout << "ScavTrap " << RED << name << RESET << " is now in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor Called" << std::endl;
}
