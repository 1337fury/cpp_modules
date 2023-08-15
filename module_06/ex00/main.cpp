/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 14:39:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/05 14:41:20 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) 
	{
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return (EXIT_FAILURE);
    }
	std::string input = argv[1];
	
	
	return (EXIT_SUCCESS);
}
