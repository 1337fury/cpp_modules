/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:39:48 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/16 10:03:07 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(const std::string& name) : name(name) {}

Data::Data() {}

Data::~Data() {}

Data::Data(const Data& other)
{
	(void)other;
}

Data& Data::operator=(const Data& copy )
{
	(void)copy;
	return *this;
}

std::string Data::get_name( void )
{
	return this->name;
}
