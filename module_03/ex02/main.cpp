/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:46:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/16 20:10:20 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    FragTrap fragTrap("Wydad");

    fragTrap.attack("Al Jahli");
    fragTrap.attack("Jrada");
    fragTrap.attack("Jrada");
    fragTrap.attack("Jrada");
    fragTrap.attack("Jrada");
    fragTrap.attack("Jrada");
    fragTrap.highFivesGuys();
    fragTrap.beRepaired(1);
    fragTrap.takeDamage(10);
    fragTrap.takeDamage(10);
    fragTrap.attack("Jrada");
    fragTrap.attack("Jrada");

    return 0;
}
