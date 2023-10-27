/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:07:39 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/10/27 16:12:34 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string exp) :
	expression(exp),
	cont(tokenize(exp))
{
}

RPN::RPN(const RPN& copy)
{
	operator=(copy);
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		expression = other.expression;
		cont = other.cont;
		stack = other.stack;
	}
	return (*this);
}

RPN::~RPN() {}

// 10 2 + 3 *
// 10 2 + 3 * 4 /
// 10 2 + 3 * 4 / 5 -
// 10 2 + 3 * 4 / 5 - 6 +
// 10 2
RPN::_Vector RPN::tokenize(std::string& s)
{
    _Vector 	container; // Container to store the tokens
    std::string temp = ""; // Temporary string to store the current token
    std::string op = "+-*/"; // Operators

	for (size_t i = 0; i < s.size(); i++)
	{
        if (std::isdigit(s[i])) // If the character is a digit
		{
            temp += s[i]; // Add it to the temporary string
			if (!temp.empty() && i == s.size() - 1) // If the temporary string is not empty and we reached the end of the string
				throw std::invalid_argument("Invalid format");
            continue; // Move to the next character
		}
        if (op.find(s[i]) != std::string::npos || std::isspace(s[i])) // If the character is an operator or a space
		{
            if (!temp.empty()) // If the temporary string is not empty
                container.push_back(temp), temp = ""; // Add it to the container and reset the temporary string

            if (op.find(s[i]) != std::string::npos) // If the character is an operator
                container.push_back(std::string(1, s[i])); // Add it to the container
		}
		else
            throw std::invalid_argument("Invalid format"); // Throw an exception for invalid characters
    }
    
    return container; // Return the container of tokens
}

void	RPN::fill_stack()
{
    // Start iterating from the last element of the container
	v_riterator it = cont.rbegin();

    // Iterate until the first element of the container
	while (it != cont.rend())
	{
        // Push the current element onto the stack
		stack.push(*it);
        
        // Move to the next element
		it++;
	}
}

int getNumber(const std::string& s)
{
	// Check if the string matches the number format using regular expression
	if (!std::regex_match(s, std::regex("[+-]?\\d+(\\.\\d+)?")))
		throw std::invalid_argument("Invalid format");

	// Convert the string to a number using atoi function
	return std::atoi(s.c_str());
}

void	operation(std::vector<std::string>& arr, std::string& op)
{
    // Check if there are at least two elements in the vector
	if (arr.size() < 2)
		throw std::invalid_argument("Invalid format");

    // Initialize variables to store the last two elements of the vector as integers
    int sum = 0;
    size_t last = arr.size() - 1;
    size_t beforeLast = arr.size() - 2;
    int numOne = std::atoi(arr[last].c_str());
    int numTwo = std::atoi(arr[beforeLast].c_str());

    // Perform the specified operation
    if (op == "+")
		sum += numTwo + numOne;
    else if (op == "-")
		sum += numTwo - numOne;
    else if (op == "*")
		sum += numTwo * numOne;
    else if (op == "/")
		sum += numTwo / numOne;

    // Remove the last two elements from the vector and add the result of the operation as a new element
	arr.erase(arr.end() - 2, arr.end());
	arr.push_back(std::to_string(sum));
}

int	RPN::calculator( void )
{
    std::vector<std::string> 	arr;
	std::string 				op = "+-*/";

	if (!stack.size())
		throw std::invalid_argument("Invalid format");
    while (!stack.empty()) {
        if (op.find(stack.top()) != std::string::npos)
            // Perform operation if top of stack is an operator
			operation(arr, stack.top());
        else
            // Add operand to the array
			arr.push_back(stack.top());
		stack.pop();
	}
    if (arr.size() > 1)
		throw std::invalid_argument("Invalid format");

    // Return the result as an integer
    return std::atoi(arr.back().c_str());
}

void	RPN::result( void )
{
	this->fill_stack();
	int	finalResult = this->calculator();
	std::cout << finalResult << std::endl;
}
