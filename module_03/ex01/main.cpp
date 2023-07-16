/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:46:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/16 19:50:21 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap scavTrap("Wydad");

    scavTrap.attack("Al Jahli");
    scavTrap.attack("Jrada");
    scavTrap.attack("Jrada");
    scavTrap.attack("Jrada");
    scavTrap.attack("Jrada");
    scavTrap.guardGate();
    scavTrap.attack("Jrada");
    scavTrap.beRepaired(1);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.takeDamage(10);
    scavTrap.attack("Jrada");
    scavTrap.attack("Jrada");
    scavTrap.guardGate();

    return 0;
}
