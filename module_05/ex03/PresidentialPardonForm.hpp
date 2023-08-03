/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:50:23 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/30 22:00:26 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_PRESIDENTIALPARDONFORM_INCLUDED
#define HEADER_PRESIDENTIALPARDONFORM_INCLUDED

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(const PresidentialPardonForm &);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		void execute(Bureaucrat const &executor) const;
		
};

#endif