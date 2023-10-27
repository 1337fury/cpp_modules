/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:54:10 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/16 10:03:14 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data("fury");

	uintptr_t serial = Serializer::serialize(&data);
	std::cout << "Data serial number: " << serial << std::endl;
 
	Data* obj = Serializer::deserialize(serial);
	std::cout << "Object name: " << obj->get_name() << std::endl;

	return 0;
}
