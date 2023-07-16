/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:56:34 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/11 10:25:06 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private :
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
	
	public :
		Contact(void);
		Contact(std::string fName, std::string lName, std::string nName, std::string pNumber, std::string dSucret);
		~Contact();
		std::string get_firstName() const;
		std::string get_lastName() const;
		std::string get_nickName() const;
		std::string get_phoneNumber() const;
		std::string get_darkestSecret() const;
};

#endif