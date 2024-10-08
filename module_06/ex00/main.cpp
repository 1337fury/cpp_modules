/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:39:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/10/24 20:39:13 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argv, char** argc)
{
    if (argv != 2)
	{
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    std::string literal(argc[1]);
    ScalarConverter::convert(literal);

    return 0;
}
