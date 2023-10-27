/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:03:09 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/10/13 12:50:01 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main() 
{
	std::cout << "\tArray with `int`" << std::endl;
    {
		Array<int> arr(5);

		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i + 1;

		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		try 
		{
			std::cout << arr[10] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	std::cout << "\tArray with `double`" << std::endl;
	{
		Array<double> arr(5);

		for (double i = 0; i < arr.size(); i++)
			arr[i] = i + 1.5264;

		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		try 
		{
			std::cout << arr[6] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
    return 0;
}