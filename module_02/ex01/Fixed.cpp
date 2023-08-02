/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:01:05 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/08/01 20:15:36 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : fixedPnt(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int inum) : fixedPnt(inum << fractional) {}

Fixed::Fixed(const float inum) : fixedPnt(roundf(inum * (1 << fractional))) {}

float Fixed::toFloat() const
{
    return static_cast<float>(fixedPnt) / (1 << fractional);
}

int Fixed::toInt() const
{
    return fixedPnt >> fractional;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    operator=(copy);
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        fixedPnt = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (fixedPnt);
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPnt = raw;
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    output << fixed.toFloat();
    return (output);
}
