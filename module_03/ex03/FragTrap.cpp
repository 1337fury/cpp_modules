/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:57:58 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/16 20:15:52 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() 
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Default Constructor Called" << std::endl;
}

FragTrap::FragTrap( const std::string name ) : ClapTrap(name)
{
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout << "FragTrap copy constructor called !" << std::endl;
	operator=(copy);
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
	{
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
    std::cout << "FragTrap copy assignment operator called !" << std::endl;
    return (*this);
}

void	FragTrap::attack( const std::string& target )
{
	if (energyPoints >= 1 && hitPoints >= 1) 
	{
		energyPoints -= 1;
		std::cout << "FragTrap " << RED << name << RESET << " attacks " << GREEN << target << RESET << ", causing " << attackDamage << " points of damage!" << std::endl;
	} else {
		std::cout << "FragTrap " << name << " doesn't have enough energy to attack!" << std::endl;
	}
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap "<< RED << name << RESET << ": Nice move! Give me a high-five!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap named " << name << " Destructor Called" << std::endl;
}
