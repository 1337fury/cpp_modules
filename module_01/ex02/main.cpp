/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:55:49 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 10:03:29 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *pBrain = &brain;
	std::string& rBrain = brain;
	//Print
	//[Address]
	std::cout << &brain << std::endl;
	std::cout << pBrain << std::endl;
	std::cout << &rBrain << std::endl;
	//[Value]
	std::cout << brain << std::endl;
	std::cout << *pBrain << std::endl;
	std::cout << rBrain << std::endl;
	return (0);
}
