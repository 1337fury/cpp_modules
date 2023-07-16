/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:06:52 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 13:46:05 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string name);
		~HumanB();
		void	attack() const;
		void	setWeapon(Weapon &weapon);

	private:
		const std::string name;
		Weapon	*weapon;
};
