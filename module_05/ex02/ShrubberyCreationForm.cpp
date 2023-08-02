/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:21:57 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/02 16:59:53 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) :
	AForm(target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &copy )
    : AForm(copy)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	if (this != &other)
        AForm::operator=(other);
    return (*this);
}

void ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	AForm::execute(executor);
	std::ofstream ofs(executor.getName() + "_shrubbery");
	ofs << "                ##### #### ##" << std::endl;
	ofs << "               # #### ####    ##" << std::endl;
	ofs << "             ### \\\\/#|### |/####" << std::endl;
	ofs << "            ##\\\\/#/ \\\\||/##/_/##/_#" << std::endl;
	ofs << "          ###  \\\\/###|/ \\\\/ # ###" << std::endl;
	ofs << "        ##_\\\\_#\\\\_\\\\## |  /###_/###" << std::endl;
	ofs << "        ## #### # \\\\ #| /  ### ###" << std::endl;
	ofs << "          __#_--###`  |{,### ###" << std::endl;
	ofs << "              \\\\ }{ \\\\#\\\\###\\\\#\\\\#" << std::endl;
	ofs << "              /\\\\#\\\\##\\\\  /##/\\\\#\\\\" << std::endl;
	ofs << "              |  ` \\\\#/`_ _`/  \\\\" << std::endl;
	ofs << "               \\\\'_'_ _| _'_` _/\\\\ " << std::endl;
	ofs << "               | ` _`'  _ _'   /" << std::endl;
	ofs << "            ( ' )  ####  ` \\\\   `-'" << std::endl;
	ofs << "           <'  `>._,  ###...###" << std::endl;
	ofs.close();
}
