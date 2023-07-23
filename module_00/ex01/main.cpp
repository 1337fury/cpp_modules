/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:13:51 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/20 17:34:59 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool	isNumber(std::string& str)
{
	if (str.length() < 10)
		return (false);
	for (std::size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (false);
	return (true);
}

bool isValid(std::string& str)
{
	for (std::size_t i = 0; i < str.length(); i++)
		if (!std::isalpha(str[i]) && !std::isspace(str[i]))
			return (false);
	return (true);
}

void	checkLoop(std::string& str, std::string info)
{
	while (!isValid(str))
	{
		std::cout << RED << "Please enter a valid info!" << RESET << std::endl;
		std::cout << info << ": ";
		std::getline(std::cin, str);
	}
}

void	_add(PhoneBook& phonebook)
{
	std::string fName, lName, nName, pNum, dSecret;

	std::cout << "First Name: ";
	std::getline(std::cin, fName);
	checkLoop(fName, "First Name");
	std::cout << "Last Name: ";
	std::getline(std::cin, lName);
	checkLoop(lName, "Last Name");
	std::cout << "Nickname: ";
	std::getline(std::cin, nName);
	checkLoop(nName, "Nickname");
	std::cout << "Phone Number: ";
	std::getline(std::cin, pNum);
	while (!isNumber(pNum))
	{
		std::cout << RED << "Please enter a valid phone number!" << RESET << std::endl;
		std::cout << "Phone Number: ";
		std::getline(std::cin, pNum);
	}
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
	phonebook.displayDetails(std::atoi(index.c_str())); //c_str convert str to C style
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
		else if (command != "EXIT")
            std::cout << RED << "Invalid command. Please try again." << RESET << std::endl;
	}
	return (0);
}
