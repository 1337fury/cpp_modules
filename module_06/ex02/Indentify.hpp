/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Indentify.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:49:18 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/20 20:53:02 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
	public:
   		virtual ~Base() {}
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate();
void identify(Base& p);
void identify(Base* p);