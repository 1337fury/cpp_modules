/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:01:39 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/10/10 16:26:40 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : max(N) {}

Span::Span(const Span& other) 
{
	operator=(other);
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		numbers = other.numbers;
		max = other.max;
	}
	return (*this);
}

void Span::addNumber(int newNumber)
{
    // Check if the size of numbers exceeds the maximum size
	if (numbers.size() >= max)
        throw Span::outOfsize(); // Throw an exception if it does

    // Add the newNumber to the numbers vector
	numbers.push_back(newNumber);
}

// Calculates the shortest span between numbers in the 'numbers' vector
// Throws an exception if the vector size is less than or equal to 1
int Span::shortestSpan(void)
{
	// Check if the vector size is less than or equal to 1
	if (numbers.size() <= 1)
		throw Span::badRange();

	// Sort the numbers in ascending order
	std::sort(numbers.begin(), numbers.end());

	// Initialize the shortest distance with the difference between the first two numbers
	int shortestDistance = numbers[1] - numbers[0];

	// Iterate through the numbers and update the shortest distance if a smaller difference is found
	for (size_t i = 2; i < numbers.size(); i++)
		shortestDistance = std::min(shortestDistance, numbers[i] - numbers[i - 1]);

	// Return the shortest distance
	return shortestDistance;
}


// Function to find the longest span in the numbers vector
int Span::longestSpan(void)
{
    // Check if the numbers vector has less than or equal to 1 element
	if (numbers.size() <= 1)
        throw Span::badRange(); // Throw an exception if the range is invalid
    
    // Sort the numbers vector in ascending order
	std::sort(numbers.begin(), numbers.end());
    
    // Return the longest distance
    return (*(numbers.end() - 1) - *numbers.begin());
}

// - There are several convenient methods available in the Standard Template Library (STL) to add multiple numbers to the Span object. However, for the purpose of emphasizing this crucial concept, I prefer utilizing variadic functions.
// Function to add multiple numbers to the Span object
void Span::multipleNumber(size_t count, ...)
{
	if (count > max)
		 throw std::invalid_argument("Count exceeds the maximum limit"); // Throw an exception if it does

    va_list args; // Create a va_list object to hold the variable arguments
    va_start(args, count); // Initialize the va_list object with the variable arguments
	
    // Iterate through the variable arguments
	for (size_t i = 0; i < count; i++)
    {
        int number = va_arg(args, int); // Get the next argument from the va_list object
        addNumber(number); // Add the number to the Span object
    }

    va_end(args); // Clean up the va_list object
}

const char* Span::outOfsize::what() const throw()
{
	return "Span is already full";
}

const char* Span::badRange::what() const throw()
{
	return "Not enough numbers to calculate span";
}

Span::~Span() {}