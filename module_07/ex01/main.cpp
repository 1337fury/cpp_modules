/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:05:31 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/06 14:39:24 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T element) 
{
    std::cout << element << " ";
}

int main()
{
    {
		int tab[] = {1, 2, 3, 4, 5};
		size_t length = sizeof(tab) / sizeof(tab[0]);

		std::cout << "Printing int array elements using iter function: ";
		::iter(tab, length, printElement<int>);
		std::cout << std::endl;
	}

    {
		double tab[] = {1.1, 2.2, 3.3, 4.4, 5.5};
		size_t length = sizeof(tab) / sizeof(tab[0]);

		std::cout << "Printing double array elements using iter function: ";
		::iter(tab, length, printElement<double>);
		std::cout << std::endl;
	}

    {
		char tab[] = {'H', 'e', 'l', 'l', 'o'};
		size_t length = sizeof(tab) / sizeof(tab[0]);

		std::cout << "Printing charArray elements using iter function: ";
		::iter(tab, length, printElement<char>);
		std::cout << std::endl;
	}
    return 0;
}