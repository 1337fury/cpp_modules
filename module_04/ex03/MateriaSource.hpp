/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:35:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/01 11:34:15 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* k_materias[4];
	
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();
		
		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};
