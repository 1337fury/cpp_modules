/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 09:22:49 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/16 11:54:36 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constractor
ClapTrap::ClapTrap() :
name("Default"),
hitPoints(10),
energyPoints(10),
attackDamage(10) 
{
	std::cout << "Default constructor called. Welcome, ClapTrap " << name << "!" << std::endl;
}

//Constractor
ClapTrap::ClapTrap( const std::string name ) : 
name(name),
hitPoints(10),
energyPoints(10),
attackDamage(10) 
{
	std::cout << "Constructor called. Welcome, ClapTrap " << name << "!" << std::endl;
}

//Copy constractor
ClapTrap::ClapTrap( const ClapTrap& copy ) :
name(copy.name),
hitPoints(copy.hitPoints),
energyPoints(copy.energyPoints),
attackDamage(copy.attackDamage)
{
	std::cout << "Copy constructor called. ClapTrap " << copy.name << " has been copied to ClapTrap " << name << "!" << std::endl;
}
//copy assignment operator
ClapTrap& ClapTrap::operator=( const ClapTrap& other )
{
	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "Assignment operator called. ClapTrap " << name << " has been assigned with ClapTrap " << other.name << "!" << std::endl;
	return (*this);
}

//Destractor
ClapTrap::~ClapTrap()
{
	std::cout << "A ClapTrap named " << name << " has been destroyed!" << std::endl;
}

//Take dammage member function
void ClapTrap::takeDamage(unsigned int amount) 
{
	if (hitPoints < 0)
		std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
	else
	{
		if (amount >= hitPoints)
		{
			hitPoints = 0;
			std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and has been destroyed!" << std::endl;
		} else
		{
			hitPoints -= amount;
			std::cout << "ClapTrap " << name << " takes " << amount << " points of damage. It has " << hitPoints << " hit points left." << std::endl;
		}
	}
}

//Attack member function
void	ClapTrap::attack( const std::string& target )
{
	if (energyPoints >= 1) 
	{
		energyPoints -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " doesn't have enough energy to attack!" << std::endl;
	}
}

//beRepaired member function
void	ClapTrap::beRepaired( unsigned int amount )
{
	if (hitPoints > 0)
	{
		hitPoints += amount;
		std::cout << "ClapTrap repairs itself" << std::endl;
	} else
		std::cout << "ClapTrap " << name << " has no hit points left and cannot be repaired!" << std::endl;
}
