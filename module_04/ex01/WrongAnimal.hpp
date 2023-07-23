/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 13:51:41 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/18 13:52:27 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal& copy);
		WrongAnimal& operator=(WrongAnimal& other);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};
