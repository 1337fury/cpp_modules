/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:03:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/12 11:39:27 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

typedef void	(Harl::*DebugPtr)( void );
typedef void	(Harl::*InfoPtr) ( void );
typedef void	(Harl::*WarningPtr) ( void );
typedef void	(Harl::*ErrorPtr) ( void );

typedef void	(Harl::*Complain[4]) (  );