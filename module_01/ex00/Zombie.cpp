/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:03:54 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 11:07:02 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name) {};
Zombie::~Zombie()
{
	 std::cout << this->name << " is destroyed. Goodbye!" << std::endl;
};

void	Zombie::announce() const
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}
