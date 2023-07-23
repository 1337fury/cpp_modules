/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:19:19 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 20:21:39 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

class Animal
{
	public:
		Animal();
		Animal(Animal& copy);
		Animal& operator=(Animal& other);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};