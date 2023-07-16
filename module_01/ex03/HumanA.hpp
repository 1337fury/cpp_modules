/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:26:35 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/13 15:50:44 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string name, Weapon& weapon);
		~HumanA();
		void	attack() const;
		
	private:
		const std::string name;
		Weapon&	weapon;
};
