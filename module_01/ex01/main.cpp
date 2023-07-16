/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:28:29 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 09:52:33 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

# define NUM_ZOMBIES 5

int main() 
{
    Zombie* horde = zombieHorde(NUM_ZOMBIES, "Ravengore");
    for (int i = 0; i < NUM_ZOMBIES; i++)
        horde[i].announce();
    delete []horde;
    return 0;
}
