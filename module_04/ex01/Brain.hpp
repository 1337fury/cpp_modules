/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:14:05 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/31 10:32:28 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		Brain& operator=(const Brain& other);
		~Brain();
	private:
		std::string ideas[100];
};
