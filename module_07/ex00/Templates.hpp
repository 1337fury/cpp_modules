/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:29:36 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/06 13:09:15 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <class T>

void	swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <class T>

T&	min(T& a, T& b)
{
	return (a == b) ? b : ((a < b) ? a : b);
}

template <class T>

T&	max(T& a, T& b)
{
	return (a == b) ? b : ((a > b) ? a : b);
}

#endif