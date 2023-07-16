/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:48:53 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/15 11:15:39 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(const float a, const float b);
		Point(Point& other);
		Point& operator=(const Point& other);
		~Point();

	private:
		Fixed x;
		Fixed y;
};
