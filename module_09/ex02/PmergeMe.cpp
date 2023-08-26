/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:25:25 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/26 11:16:20 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
 *	C++11 Version [Regex]
 */
// PmergeMe::PmergeMe(char **argv, int argc) 
// {
// 	for (int i = 1; i < argc; i++)
// 	{
// 		if (!std::regex_match(std::string(argv[i]), std::regex("[+-]?\\d+")))
// 			throw std::invalid_argument("Error: Invalid positive integer sequence provided.");
// 		int	element = std::atoi(argv[i]);
// 		addElement(element);
// 	}
// }

PmergeMe::PmergeMe(char **argv, int argc) {
    // Compile the regular expression
    regex_t regex;
    int ret = regcomp(&regex, "^[+-]?[0-9]+$", REG_EXTENDED);
    if (ret)
         throw std::runtime_error("Error: Could not compile regex.");

    // Iterate through the command line arguments
    for (int i = 1; i < argc; ++i)
	{
        // Check if the argument matches the regular expression
        ret = regexec(&regex, argv[i], 0, NULL, 0);
       	if (ret == REG_NOMATCH)
            throw std::invalid_argument("Error: Invalid positive integer sequence provided.");
        // Convert the argument to an integer and add it to the element list
        int element = atoi(argv[i]);
		addElement(element);
	}
}

void	PmergeMe::addElement(int element)
{
	vectorS.push_back(element);
	listS.push_back(element);
}

template <class Container>
void	PmergeMe::displaySequence(const std::string& message, const Container& sequence)
{
	std::string	color;
	message == "Before: " ? color = RED : color = GREEN;
	typename Container::const_iterator it = sequence.begin();
    std::cout << color << message << RESET;
	for (; it != sequence.end(); it++)
        std::cout << color << *it << " ";
    std::cout << RESET << std::endl;
}

template <class Iterator, class Container>
void	PmergeMe::merge(Container& sequence, Iterator begin, Iterator middle, Iterator end)
{
	(void)sequence;
    // Create containers for the left and right halves of the sequence
    Container left(begin, middle);
    Container right(middle, end);

    // Create iterators for the left, right, and sequence containers
	Iterator leftIt = left.begin();
	Iterator rightIt = right.begin();
	Iterator sequenceIt = begin;

    // Merge the left and right halves of the sequence
	while (leftIt != left.end() && rightIt != right.end())
	{
		if (*leftIt <= *rightIt)
		{
            // Copy element from the left half to the sequence
			*sequenceIt = *leftIt;
			++leftIt;
		}
		else
		{
            // Copy element from the right half to the sequence
			*sequenceIt = *rightIt;
			++rightIt;
		}
		++sequenceIt;
	}

    // Copy any remaining elements from the left half to the sequence
	while (leftIt != left.end())
	{
		*sequenceIt = *leftIt;
		++leftIt;
		++sequenceIt;
	}

    // Copy any remaining elements from the right half to the sequence
	while (rightIt != right.end())
	{
		*sequenceIt = *rightIt;
		++rightIt;
		++sequenceIt;
	}
}

// This function performs a merge-insertion sort on a sequence using the given iterators.
template <class Iterator, class Container>
void	PmergeMe::mergeInsertSort(Container& sequence, Iterator begin, Iterator end)
{
    // If the distance between the iterators is less than or equal to 1, the sequence is already sorted.
	if (std::distance(begin, end) <= 1)
		return ;

    // Find the middle iterator by advancing it halfway between the begin and end iterators.
	Iterator middle = begin;
	std::advance(middle, std::distance(begin, end) / 2);

    // Recursively call mergeInsertSort on the first half of the sequence.
	mergeInsertSort(sequence, begin, middle);

    // Recursively call mergeInsertSort on the second half of the sequence.
	mergeInsertSort(sequence, middle, end);

    // Merge the two sorted halves of the sequence.
	merge(sequence, begin, middle, end);
}

void	PmergeMe::mergeMe( void )
{
	{
		std::cout << RESET << std::endl;
		displaySequence("Before: ", vectorS);
		std::clock_t start = std::clock();
		mergeInsertSort(vectorS, vectorS.begin(), vectorS.end());
		std::clock_t end = std::clock();
		std::cout << RESET << std::endl;
		displaySequence("After: ", vectorS);
		double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000000;
		std::cout << RESET << std::endl;
		std::cout << "Time to process a range of " << vectorS.size() << " elements with std::vector: " << duration << " us" << std::endl;
	}

	{
		std::clock_t start = std::clock();
		mergeInsertSort(listS, listS.begin(), listS.end());
		std::clock_t end = std::clock();
		double duration = (end - start) / (double)CLOCKS_PER_SEC * 1000000;
		std::cout << "Time to process a range of " << vectorS.size() << " elements with std::list: " << duration << " us" << std::endl;
	}
}