/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:03:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/12 14:41:50 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

# define USAGE "Usage: ./harlFilter <level>"

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
