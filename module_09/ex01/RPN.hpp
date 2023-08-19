/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:05:40 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/19 12:23:37 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <stack>
#include <regex>
#include <array>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"
# define USAGE "./RPN <Expression>"

class RPN
{
	public:
		RPN(std::string exp);
		RPN(const RPN&);
		RPN& operator=(const RPN&);
		~RPN();

		typedef std::vector<std::string> 					_Vector;
		typedef std::vector<std::string>::iterator 			v_iterator;
		typedef std::vector<std::string>::reverse_iterator 	v_riterator;

		_Vector tokenize(std::string& s);
		void	fill_stack( void );
		int		calculator( void );
		void	result( void );
	
	private:
		std::string				expression;
		_Vector 				cont;
		std::stack<std::string> stack;
};