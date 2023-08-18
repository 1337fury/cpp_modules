/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:39:47 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/16 12:35:45 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

// MutantStack class derived from std::stack
template <class T>
class MutantStack : public std::stack<T>
{
	public:
    // Default constructor
		MutantStack() {}

    // Copy constructor
		MutantStack(const MutantStack<T>& other) {(void)other;}

    // Assignment operator
		MutantStack<T>& operator=(const MutantStack<T>& other) {(void)other; return(this);}

    // Destructor
		~MutantStack() {}
		
    // Define iterator and const_iterator types
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator  reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Inherit constructor from std::stack
		using typename std::stack<T>::stack;

    // Return iterator to the beginning of the container
		iterator begin() {return std::stack<T>::c.begin();}
		

    // Return iterator to the end of the container
		iterator end() {return std::stack<T>::c.end();}

    // Return const_iterator to the beginning of the container
		const_iterator begin() const {return std::stack<T>::c.begin();}


    // Return const_iterator to the end of the container
		const_iterator end() const {return std::stack<T>::c.end();}

    // Return reverse_iterator to the beginning of the container
		reverse_iterator rbegin() {return std::stack<T>::c.rbegin();}

    // Return reverse_iterator to the end of the container
		reverse_iterator rend() {return std::stack<T>::c.rend();}

    // Return const_reverse_iterator to the beginning of the container
    const_reverse_iterator rbegin() const {return std::stack<T>::c.rbegin();}

    // Return const_reverse_iterator to the end of the container
    const_reverse_iterator rend() const {return std::stack<T>::c.rend();}
};
