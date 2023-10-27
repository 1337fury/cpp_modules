/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 11:46:47 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/09/20 19:34:09 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {*this = other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// Checks if the given string is a single printable character
bool isSinglePrintableCharacter(const std::string& literal)
{
    // Check if the length of the string is 1
    // and if the character at index 0 is an alphabetic printable character
	return (literal.length() == 1 && std::isalpha(literal[0]) && std::isprint(literal[0]));
}

// Function to check if a string represents an integer
bool isInteger(const std::string literal)
{
    size_t i = 0;
    
    // Check if the first character is a sign (+ or -)
	if (literal[i] == '-' || literal[i] == '+')
		i++;
    
    // Iterate through the remaining characters in the string
	for (size_t j = i; j < literal.length(); j++)
	{
        // Check if the character is not a digit
		if (!std::isdigit(literal[j]))
            return false;
    }
    
    return true;
}

// Function to check if a string represents a valid floating point integerber
bool isFloat(const std::string literal)
{
    size_t i = 0;
    size_t point = 0;
    // Check if the string has a decimal point and if it is in the correct position
    if (literal.find('.') == std::string::npos || literal.find('.') == 0 ||
        literal.find('.') == literal.length() - 2 || literal.back() != 'f')
        return false;

    // Skip the sign if present
    if (literal[i] == '-' || literal[i] == '+')
		i++;

    // Iterate through the string to check if it contains only digits and a maximum of one decimal point
    for (size_t j = i; j < literal.length() - 1; j++)
	{
        if (literal[j] == '.')
			point++;
        if ((!std::isdigit(literal[j]) && literal[j] != '.') || point > 1)
            return false;
	}
	return (true);
}

// Function to check if a string is a valid double
bool isDouble(const std::string literal)
{
    // Initialize variables
    size_t i = 0;
    size_t point = 0;
    
    // Check if there is a decimal point and if it is at the beginning or end of the string
    if (literal.find('.') == std::string::npos || literal.find('.') == 0 || literal.find('.') == literal.length() - 1)
        return false;
    
    // Check if the first character is a minus or plus sign, if so, increment i
	if (literal[i] == '-' || literal[i] == '+')
		i++;
    
    // Loop through each character in the string
	for (size_t j = i; j < literal.length(); j++)
	{
        // Check if the character is a decimal point, increment point
		if (literal[j] == '.')
			point++;
        
        // Check if the character is not a digit or a decimal point, or if there are more than one decimal points
		if ((!std::isdigit(literal[j]) && literal[j] != '.') || point > 1)
            return false;
    }

    // If all checks pass, return true
    return true;
}

// Check if the given string is a literal
bool isLiteral(const std::string literal) {
    // Array of literal strings to compare with
	std::string literals[6] = {"nan", "nanf", "+inf", "-inf", "-inff", "+inff"};
    
    // Iterate through the array of literals
    for (int i = 0; i < 6; i++)
	{
        // Compare the given string with each literal
        if (!literal.compare(literals[i]))
            return true; // Return true if a match is found
    }
    
    return false; // Return false if no match is found
}


void	toOut(const std::string literal, t_data types)
{
	std::cout << "char: ";
	if (isLiteral(literal) || (types.integer > 126 || types.integer < 0))	
		std::cout << "Impossible";
	else if (!std::isprint(types.integer))
		std::cout << "None displayable";
	else
		std::cout << "'" << types.c << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (isLiteral(literal) || types.imposi || (types._float > 2147483647 || types._float < -2147483648)
		|| (types._double > 2147483647 || types._double < -2147483648))
		std::cout << "Impossible";
	else
		std::cout << types.integer;
	std::cout << std::endl;

	std::cout << "Float: ";
	if (types.imposi)
		std::cout << "Impossible";
	else if (isLiteral(literal))
	{
		if (literal[0] == '+' || literal[0] == '-')
			std::cout << literal.substr(0, 4) << "f";
		else
			std::cout << literal.substr(0, 3) << "f";
	}
	else
	{
		types._float - static_cast<int>(types._float) == 0 ? std::cout << types._float << ".0f" :
		std::cout << types._float << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (types.imposi)
		std::cout << "Impossible";
	else if (isLiteral(literal))
	{
		if (literal[0] == '+' || literal[0] == '-')
			std::cout << literal.substr(0, 4);
		else
			std::cout << literal.substr(0, 3);
	}
	else
	{
		types._double - static_cast<int>(types._double) == 0 ? std::cout << types._double << ".0" : std::cout << types._double;
	}
	std::cout << std::endl;
}


void ScalarConverter::convert( const std::string literal ) {
	t_data	data_types;

	data_types.c = '\0';
	data_types.integer = 0;
	data_types._float = 0.0f;
	data_types._double = 0.0;
	data_types.imposi = false;

  if (isSinglePrintableCharacter( literal )) {
	
	   	data_types.c = literal[0];

        data_types.integer = static_cast< int >( data_types.c );
        data_types._float = static_cast< float >( data_types.c );
        data_types._double = static_cast< double >( data_types.c );
	} else if (isInteger( literal )) {
		
		data_types.integer = std::atoi(literal.c_str());
		
        data_types._float = static_cast< float >( data_types.integer );
        data_types._double = static_cast< double >( data_types.integer );
        data_types.c = static_cast< char >( data_types.integer );
	} else if (isFloat( literal )) {
    	data_types._float = std::atof(literal.c_str());

        data_types.integer = static_cast< int >( data_types._float );
        data_types._double = static_cast< double >( data_types._float );
        data_types.c = static_cast< char >( data_types._float );
	} else if (isDouble( literal )) {
		
    	data_types._double = std::strtod(literal.c_str(), NULL);
		
        data_types.integer = static_cast< int >( data_types._double );
        data_types._float = static_cast< float >( data_types._double );
        data_types.c = static_cast< char >( data_types._double );
	} else if (!isLiteral( literal )) {
		std::cout << "Error: Unknown type" << std::endl;
        return;	
	}
	toOut( literal , data_types);
}