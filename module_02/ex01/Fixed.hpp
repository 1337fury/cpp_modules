/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:49:28 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/13 13:28:59 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed( void );
		Fixed( const int inum );
		Fixed( const float fnum );
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed();
		int	getRawBits(  void ) const;
		void setRawBits( int const raw );

	private:
		int	 	 		 fixedPnt;
		static const int fractional;
};

std::ostream& operator<<(std::ostream& output, const Fixed& fixed);