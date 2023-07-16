/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:31:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 10:26:03 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}
Contact::Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSucret) 
	: firstName(fName), lastName(lName), nickName(nName), phoneNumber(pNumber), darkestSecret(dSucret) {}
Contact::~Contact() {}

std::string Contact::get_firstName() const
{
	return (firstName);
}

std::string Contact::get_lastName() const
{
	return (lastName);
}

std::string Contact::get_nickName() const
{
	return (nickName);
}

std::string Contact::get_phoneNumber() const
{
	return (phoneNumber);
}

std::string Contact::get_darkestSecret() const
{
	return (darkestSecret);
}
