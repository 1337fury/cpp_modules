/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:35:30 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/01 11:32:19 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() 
{
	for (int i = 0; i < 4; i++)
		k_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	operator=(copy);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			if (k_materias[i])
				delete k_materias[i], k_materias[i] = NULL;
		for (int i = 0; i < 4; i++)
			if (other.k_materias[i])
				this->k_materias[i] = other.k_materias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {}


//Copies the Materia passed as a parameter and store it in memory so it can be cloned later. Like the Character, the MateriaSource can know at most 4 Materias. They are not necessarily unique
void	MateriaSource::learnMateria(AMateria *item)
{
	if (item == NULL)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!k_materias[i])
		{
			k_materias[i] = item->clone();
			delete item;
			break ;
		}
	}
}

//Returns a new Materia. The latter is a copy of the Materia previously learned by the MateriaSource whose type equals the one passed as parameter. Returns 0 if the type is unknown.
AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (k_materias[i] && k_materias[i]->getType() == type)
			return (k_materias[i]);
	return (NULL);
}
