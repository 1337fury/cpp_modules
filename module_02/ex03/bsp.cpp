/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:06:33 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/27 19:01:45 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	/*
	[1]
		Calculate the area of the given triangle:
		A = [Ax(By – Cy) + Bx(Cy – Ay) + Cx(Ay - By)]/2
	 */
	float	abc_area = (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
						+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
						+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2;
	/*
	[2]
		Calculate the area of triangle PAB
	*/
	float	pab_area = (point.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())
						+ a.getX().toFloat() * (b.getY().toFloat() - point.getY().toFloat())
						+ b.getX().toFloat() * (point.getY().toFloat() - a.getY().toFloat())) / 2;
	/*
	[3]
		Calculate the area of triangle PBC
	*/
	float	pbc_area = (point.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
						+ b.getX().toFloat() * (c.getY().toFloat() - point.getY().toFloat())
						+ c.getX().toFloat() * (point.getY().toFloat() - b.getY().toFloat())) / 2;
	/*
	[4]
		Calculate the area of triangle PAC
	*/
	float	pac_area = (point.getX().toFloat() * (a.getY().toFloat() - c.getY().toFloat())
						+ a.getX().toFloat() * (c.getY().toFloat() - point.getY().toFloat())
						+ c.getX().toFloat() * (point.getY().toFloat() - a.getY().toFloat())) / 2;
	if (!floor(pab_area) || !floor(pbc_area) || !floor(pac_area))
		return (false);
	return (abs(pab_area) + abs(pbc_area) + abs(pac_area) == abs(abc_area));
}
