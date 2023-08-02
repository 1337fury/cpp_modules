/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:53:20 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/31 15:49:38 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << RED << USAGE << RESET << std::endl, 1);

	std::string	needle = av[2];
	std::string _new = av[3];
	std::ifstream infile(av[1]);
	std::ofstream outfile(std::strcat(av[1], ".replace"));
	std::string finalResult = "";

	if (infile.is_open() && outfile.is_open())
	{
		std::string line;
		std::size_t	needleLen = needle.length();
		std::size_t newLen = _new.length();
		std::size_t pos = 0;

		while (std::getline(infile, line))
		{
			while ((pos = line.find(needle, pos)) != std::string::npos)
			{
				line.erase(pos, needleLen);
				line.insert(pos, _new);
				pos += newLen;
			}
			finalResult += line;
		}
		outfile << finalResult;
		infile.close();
		outfile.close();
	}
	else
		return (std::cerr << RED << OFAIL << RESET << std::endl, 1);
}
