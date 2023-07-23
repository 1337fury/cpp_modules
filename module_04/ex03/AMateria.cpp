/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:27:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/20 13:11:15 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : type(type) {}

AMateria::~AMateria() {}

const std::string&	AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter& target) 
{
	std::cout << "AMateria::use => " + target.getName() << std::endl;
}
