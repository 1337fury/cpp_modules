/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:00:39 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/07 11:01:17 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <class T>
Array<T>::Array() : data(NULL), _size(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _size(n)
{
	data = new T[_size];
}

template <class T>
Array<T>::Array(const Array& other) : _size(other._size)
{
	data = new T[_size];
	for (int i = 0; i < _size; i++)
		data[i] = other.data[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		delete[] data;
		_size = other._size;
		data = new T[_size];
		for (int i = 0; i < _size; i++)
			data[i] = other.data[i]; 
	}
    return (*this);
}

template <class T>
Array<T>::~Array() 
{
	delete[] data;
}

template <class T>

T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (data[index]);
}

template <class T>
unsigned int Array<T>::size() const 
{
    return _size;
}

#endif // ARRAY_TPP
