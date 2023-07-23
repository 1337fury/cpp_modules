/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:03:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/20 12:37:38 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("default")
{
	for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
};

Character::Character(std::string name) : name(name)
{
	for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
};

Character::~Character() 
{
	for (int i = 0; i < 4; ++i)
    {
        if (inventory[i])
            delete inventory[i];
    }
};

Character::Character(const Character& copy) : name(copy.name)
{
	operator=(copy);
}

Character& Character::operator=(const Character& other)
{
	//he Materias of a Character must be deleted before the new ones are added to their inventory.
	if (this != &other)
	{
		//deep copy
		for (int i = 0; i < 4; i++)
			if (inventory[i])
				delete this->inventory[i], this->inventory[i] = NULL;
		name = other.name;
		for (int i = 0; i < 4; i++)
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		// They equip the Materias in the first empty slot they find.
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx > 3 || idx < 0 || inventory[idx] == NULL)
		return ;
	// The unequip() member function must NOT delete the Materia!
	inventory[idx] = NULL; // No delete here
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
        return;
	//use the Materia at the slot[idx], and pass the target parameter to the AMateria::use function
    inventory[idx]->use(target);
}
