/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:59:41 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/27 19:06:33 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) 
{
	{
		Point	a(20,80);
		Point	b(20,40);
		Point	c(80,40);

		Point	p(20.9,79);

		std::string res = bsp( a, b, c, p ) ? "The point is inside the triangle." : "The point is outside the triangle.";
		std::cout << res << std::endl;
	}
	
	{
		Point	a(20,80);
		Point	b(20,40);
		Point	c(80,40);

		Point	p(10,79);


		std::string res = bsp( a, b, c, p ) ? "The point is inside the triangle." : "The point is outside the triangle.";
		std::cout << res << std::endl;
	}
	return 0;
}
