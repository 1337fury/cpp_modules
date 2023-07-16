/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 10:05:49 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 10:27:36 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : numContacts(0) {
	for (int i = 0; i < MAX; i++)
	{
		Contact contact("", "", "", "", "");
		contacts[i] = contact;
	}
}
PhoneBook::~PhoneBook() {}

void	PhoneBook::add(Contact& newC)
{
	if (numContacts < MAX)
		contacts[numContacts++] = newC;
	else
	{
		for (int i = 0; i < MAX - 1; i++)
			contacts[i] = contacts[i + 1];
		contacts[MAX - 1] = newC;
	}
};

void	PhoneBook::displayContacts() const
{
	if (!numContacts)
	{
		std::cout << "Phonebook is empty. Add contacts before searching." << std::endl;
		return ;
	}
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < numContacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << truncateStr(contacts[i].get_firstName()) << "|";
		std::cout << std::setw(10) << truncateStr(contacts[i].get_lastName()) << "|";
		std::cout << std::setw(10) << truncateStr(contacts[i].get_nickName()) << "|" << std::endl;
	}
}

void	PhoneBook::displayDetails(int index) const
{
	if (index >= 1 && index <= numContacts)
	{
		std::cout << "First Name: " << contacts[index - 1].get_firstName() << std::endl;
		std::cout << "Last Name: " << contacts[index - 1].get_lastName() << std::endl;
		std::cout << "Nickname: " << contacts[index - 1].get_nickName() << std::endl;
		std::cout << "Phone Number: " << contacts[index - 1].get_phoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[index - 1].get_darkestSecret() << std::endl;
	} else
		std::cout << RED << "Enter a valid index!" << RESET << std::endl;
}

std::string	PhoneBook::truncateStr(std::string str) const
{
	const int	WIDTH = 10;
	if (str.length() <= WIDTH)
		return (str);
	else
		return (str.substr(0, WIDTH - 1) + ".");
}
