/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:55:54 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/22 18:37:25 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <stdlib.h>

// Template function that iterates over an array and applies a function to each element
template <class T, class F>
void	iter(T* array, size_t length, F function)
{
	for (size_t i = 0; i < length; i++)
        function(array[i]); // Apply the function to the current element
}

#endif