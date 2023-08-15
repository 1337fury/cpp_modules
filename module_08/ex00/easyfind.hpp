#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>


template <class T>
typename T::iterator	easyfind(T& container, int toFind);

#include "easyfind.tpp"

#endif
