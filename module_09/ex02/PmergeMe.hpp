/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:24:28 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/25 20:53:32 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <regex.h>

# define GREEN "\033[32m"
# define RESET "\033[0m"
# define RED "\033[31m"

class PmergeMe 
{
	private:
		std::vector<int>	vectorS;
		std::list<int>		listS;

	public:
		PmergeMe(char**, int);
		void	addElement(int);
		
		template <class Container>
		void	displaySequence(const std::string&, const Container&);
		
		template <class Iterator, class Container>
		void	merge(Container&, Iterator, Iterator, Iterator);
		
		template <class Iterator, class Container>
		void	mergeInsertSort(Container&, Iterator, Iterator);
	
		void	mergeMe( void );
};
