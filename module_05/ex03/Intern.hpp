/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:37:52 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/03 12:49:44 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern(); // Default constructor
		Intern(const Intern& other); // Copy constructor
		Intern& operator=(const Intern& other); // Copy assignment operator
		~Intern(); // Destructor

		AForm* makeForm(const std::string& name, const std::string& target);

	private:
		// Add private member variables here
};
#endif // INTERN_HPP