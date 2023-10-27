/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:37:37 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/01 12:57:30 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void	_perror(std::string errorMsg)
{
	std::cerr << RED << errorMsg << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string BaseName, std::string fileName) :
	dataBase(BaseName),
	inputFile(fileName)
{
	if (!dataBase.is_open())
		 throw std::runtime_error("Remove " + BaseName + " or rename it is a stupid idea!");
	if (!inputFile.is_open())
		throw std::runtime_error("Failed to open file: " + fileName);
}

BitcoinExchange::~BitcoinExchange()
{
    dataBase.close();
    inputFile.close();
}

void	BitcoinExchange::processFile( void )
{
	std::string	line;
	size_t		sepPos;
	pair 		_pair;

	std::getline(dataBase, line); //Skip the first line
	while (std::getline(dataBase, line))
	{
		sepPos = line.find(",");
		_pair = std::make_pair(line.substr(0, sepPos), line.substr(sepPos + 1));
		mapedData.insert(_pair);
	}
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void)other;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {(void)copy;}

// Function to check the value in a given line
bool check_value(std::string line)
{
    // Find the position of the separator " | "
    size_t sepPos = line.find(" | ");
    
    // Extract the date string from the line
    std::string dateStr = line.substr(0, sepPos);
    
    // Extract the value string from the line
    std::string valueStr = line.substr(sepPos + 3);
	
    // Convert the value string to double
    double value = std::stod(valueStr);
    
    // Check if the value is less than 0
	if (value < 0)
	{
		_perror(std::string("Error: not a positive number."));
		return false;
	}
    // Check if the value is greater than 1000
	else if (value > 1000)
	{
		_perror(std::string("Error: too large a number."));
		return false;
	}
    
    // Return true if the value is valid
    return true;
}

std::string convertDate(std::string date)
{
	/*
		"1234-56-78" => Remove 12345678--
				return iterator to	   ^
		 Erase from the iterator returned by  remove  until the end
	*/
    date.erase(std::remove(date.begin(), date.end(), '-'), date.end());
    return date;
}

// This function searches for the closest date in the mapedData to the input date
BitcoinExchange::iterator BitcoinExchange::findClosestDate(const std::string& date)
{
    // If the mapedData is empty, return the end of the mapedData
    if (mapedData.empty())
        return mapedData.end();

    // Convert the input date to a string
    std::string targetDate = convertDate(date);

    // Set the iterator to the beginning of the mapedData and set the closestDate to it
    iterator it = mapedData.begin();
    iterator closestDate = it;

    // Calculate the difference between the input date and the first date in the mapedData
    double closestDifference = std::abs(std::stod(targetDate) - std::stod(convertDate(it->first)));

    // Loop through the mapedData to find the closest date
    while (++it != mapedData.end())
    {
        // Convert the date to a string and calculate the difference between it and the input date
        std::string currentDate = convertDate(it->first);
        double diff = std::abs(std::stod(targetDate) - std::stod(currentDate));

        // If the date is less than or equal to the input date and the difference is less than the current closest, update the closest and closestDate variables
        if (std::stod(currentDate) <= std::stod(targetDate) && diff < closestDifference)
        {
            closestDifference = diff;
            closestDate = it;
        }
    }

    // Return the closestDate iterator
    return closestDate;
}

void BitcoinExchange::calculate_value(std::string& line)
{
    // Find the position of the separator
    size_t sepPos = line.find(" | ");
    
    // Extract the date string and value string from the line
    std::string dateStr = line.substr(0, sepPos);
    std::string valueStr = line.substr(sepPos + 3);

    // Check if the date exists in the map
	iterator found;
	if ((found = mapedData.find(dateStr)) != mapedData.end())
	{
        // Calculate and print the value
		std::cout << dateStr << " => " << valueStr << " = ";
		std::cout << (std::stod(found->second) * std::stod(valueStr)) << std::endl;
	}
	else
	{
        // Find the closest date in the map
		iterator closestDate = findClosestDate(dateStr);
        
        // Calculate and print the value
		std::cout << closestDate->first << " => " << valueStr << " = ";
		std::cout << (std::stod(closestDate->second) * std::stod(valueStr)) << std::endl;
	}
}

// This function checks if the date in the given string is in a logical format
// Input: a string containing a date in the format "YYYY-MM-DD | ..."
// Output: a boolean value indicating whether the date is in a logical format or not
bool isDateLogical(std::string& line)
{
    // Find the position of the separator between the date and the rest of the string
    size_t sepPos = line.find(" | ");
    
    // Extract the date from the string
    std::string date = line.substr(0, sepPos);
    
    // Convert the date to a struct tm object using strptime
    struct tm tm;
    if (strptime(date.c_str(), "%Y-%m-%d", &tm))
        return true;
    else
        return false;
}

void BitcoinExchange::processInput( void )
{
    std::string line;
    std::regex format("\\d{4}-\\d{2}-\\d{2} \\| \\d+(\\.\\d+)?");

    // Skip the first line from the input file
	std::getline(inputFile, line);

    // Process each line in the input file
	while (std::getline(inputFile, line))
	{
        // Skip empty lines
		if (line.empty())
		{
			_perror(std::string("Error: Empty line."));
			continue ;
		}

        // Check if the line matches the expected format
		if (!std::regex_match(line, format))
		{
			_perror(std::string("Error: bad input => ") + line);
			continue ;
		}

        // Check if the date in the line is logical
		if (!isDateLogical(line))
		{
			_perror(std::string("Error: bad date => ") + line);
			continue ;
		}

        // Check the value in the line
		if (!check_value(line))
			continue ;

        // Calculate the value
		calculate_value(line);
	}
}