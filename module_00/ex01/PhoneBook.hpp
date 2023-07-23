/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:49:58 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/20 17:36:37 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

# define MAX 8

class PhoneBook
{
	private :
		Contact contacts[MAX];
		int	numContacts;
		std::string	truncateStr(std::string str) const;

	public :
		PhoneBook();
		~PhoneBook();
		void	add(Contact& contact);
		void	displayContacts() const;
		void	displayDetails(int index) const;
};

#endif
