/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:37:23 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/03 17:01:31 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <unistd.h>

int main()
{
	{
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j; //should not create a leak
        delete i;
        puts(" "), system("leaks Brain");
        sleep(2) , system("clear");
    }
	
	const int size = 10;

	Animal *animals[size];
	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// clean
	for (int i = 0; i < size; i++)
		delete animals[i], animals[i] = NULL;
	system("leaks Brain"), exit(EXIT_SUCCESS);
	return 0;
}
