/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 12:00:08 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/14 09:35:19 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <cstdarg>
#include <stdexcept>
#include <iostream>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void	addNumber(int newNumber);
		int		shortestSpan(void);
		int		longestSpan(void);

		void	multipleNumber(size_t count, ...);

		class outOfsize : public std::exception
		{
			const char* what() const throw();
		};

		class badRange : public std::exception
		{
			const char* what() const throw();
		};

	private:
		std::vector<int> numbers;
		Span();
		unsigned int max;
};

#endif  // SPAN_HPP