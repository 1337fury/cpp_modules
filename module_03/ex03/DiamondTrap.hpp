/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:11:32 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 10:06:25 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap(const std::string& name);
		DiamondTrap(const DiamondTrap& copy);
		DiamondTrap& operator=(const DiamondTrap& othere);
		~DiamondTrap( void );
		
		void attack(const std::string &target);
    	void whoAmI();

	private:
		std::string name;
};
