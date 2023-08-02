/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 10:46:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/31 10:59:23 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    // Create a ClapTrap object using the default constructor
    ClapTrap clapTrap1;
    
    // Create a ClapTrap object with a specific name using the constructor
    ClapTrap clapTrap2("Robot1");
    
    // Create a copy of clapTrap2 using the copy constructor
    ClapTrap clapTrap3 = clapTrap2;
    
    // Assign clapTrap1 with clapTrap3 using the assignment operator
    clapTrap1 = clapTrap3;
    
    // Call member functions on the ClapTrap objects
    clapTrap1.attack("Target1");
    clapTrap2.takeDamage(5);
    clapTrap3.beRepaired(3);
    
    return 0;
}
