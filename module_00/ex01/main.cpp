/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:13:51 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/10 13:34:54 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	_add(PhoneBook& phonebook)
{
	std::string fName, lName, nName, pNum, dSecret;

	std::cout << "First Name: ";
	std::getline(std::cin, fName);
	std::cout << "Last Name: ";
	std::getline(std::cin, lName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nName);
	std::cout << "Phone Number: ";
	std::getline(std::cin, pNum);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, dSecret);
	
	if (fName.empty() || lName.empty() || nName.empty() || pNum.empty() || dSecret.empty())
	{
		std::cout << RED << "Error: Required fields (First Name, Last Name, Nickname, Phone Number and Darkest Secret) must not be empty." << RESET << std::endl;
        return;
	}
	Contact contact(fName, lName, nName, pNum, dSecret);

	phonebook.add(contact);
	std::cout << GREEN << "Contact added successfully" << RESET << std::endl;
}

void	_search(PhoneBook& phonebook)
{
	std::string index;

	phonebook.displayContacts();
	std::cout << "Enter the index of the contact: ";
	std::getline(std::cin, index);
	phonebook.displayDetails(stoi(index));
}

int main(void)
{
	PhoneBook	PhoneBook;
	std::string command;

	while (command != "EXIT")
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD")
			_add(PhoneBook);
		else if (command == "SEARCH")
			_search(PhoneBook);
		else
            std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
	}
	return (0);
}
