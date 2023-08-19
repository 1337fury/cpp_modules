/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:37:41 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/18 11:33:41 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <regex>
#include <map>
#include <cmath>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

# define OFAIL "Error: could not open file."
#define USAGE "./btc input_file"

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string, std::string);
		BitcoinExchange(const BitcoinExchange&);
		BitcoinExchange& operator=(const BitcoinExchange&);
		~BitcoinExchange();

		typedef std::pair<std::string, std::string> pair;
		typedef std::map<std::string, std::string>::iterator iterator;
		typedef std::map<std::string, std::string>::reverse_iterator revers_iterator; //usless

		//Costum Methods
		void		processFile( void );
		void		processInput( void );
		void		calculate_value(std::string& line);
		iterator 	findClosestDate(const std::string& date);

	private:
		std::ifstream						dataBase;
		std::ifstream						inputFile;
		std::map<std::string, std::string>	mapedData;
};
