/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:48:53 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/27 17:12:57 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float a, const float b);
		Point& operator=(const Point& other);
		Point(Point& other);
		Fixed	getX() const;
		Fixed	getY() const;
		~Point();

	private:
		Fixed x;
		Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
