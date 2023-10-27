/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 09:39:52 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/20 17:14:52 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Data
{
	private:
		Data();
		std::string name;
	public:
		Data(const std::string& name);
		Data(const Data& other);
		Data& operator=(const Data& copy );
		~Data();

		std::string	get_name( void );
};

