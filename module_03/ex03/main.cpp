/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:46:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 12:07:54 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap dia = DiamondTrap("ZAZA");

    DiamondTrap sia;
    
    sia = dia;

    dia.attack("9IRCH");
    sia.attack("JEN");
    dia.takeDamage(14);
    dia.whoAmI();
    dia.attack("JEN");

    return (EXIT_SUCCESS);
}
