/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:17:01 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/20 16:08:40 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[]) 
{
    if (argc > 1)
	{
        for (int i = 1; i < argc; i++)
		{
            std::string message = argv[i];

            for (size_t j = 0; j < message.length(); j++)
			{
                char c = std::toupper(message[j]);
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
	else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (EXIT_SUCCESS);
}
