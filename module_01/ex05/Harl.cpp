/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:41:01 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/12 12:18:01 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};


void Harl::complain( std::string level )
{
	DebugPtr	debugPtr   = &Harl::debug;
	InfoPtr		infoPtr    = &Harl::info;
	WarningPtr	warningPtr = &Harl::warning;
	ErrorPtr	errorPtr   = &Harl::error;

	Complain 	comp = {debugPtr, infoPtr, warningPtr, errorPtr};
	std::string lev[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
		if (level == lev[i])
			(this->*comp[i])();
}

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon for my7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
