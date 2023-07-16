/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 20:00:59 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 10:12:48 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie ( void );
		Zombie( std::string name );
		~Zombie();
		void	announce( void );
		void	setName( std::string name );

	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );
Zombie*	zombieHorde( int N, std::string name);

#endif
