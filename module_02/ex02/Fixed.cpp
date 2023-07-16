/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdeel-o <abdeel-o@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 10:01:05 by abdeel-o          #+#    #+#             */
/*   Updated: 2023/07/15 14:45:16 by abdeel-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional = 8;

Fixed::Fixed() : fixedPnt(0) 
{
    // std::cout << "Default constructor called" << std::endl;
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
    // std::cout << "Copy constructor called" << std::endl;
    operator=(copy);
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy)
        fixedPnt = copy.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPnt);
}

void Fixed::setRawBits( int const raw )
{
    this->fixedPnt = raw;
}

/*
    -[**Comparison Operators**]
 */

bool    Fixed::operator>(const Fixed& copy) const
{
    return (this->fixedPnt > copy.fixedPnt);
}

bool    Fixed::operator<(const Fixed& copy) const
{
    return (this->fixedPnt < copy.fixedPnt);
}

bool    Fixed::operator>=(const Fixed& copy) const
{
    return (this->fixedPnt >= copy.fixedPnt);
}

bool    Fixed::operator<=(const Fixed& copy) const
{
    return (this->fixedPnt <= copy.fixedPnt);
}

bool    Fixed::operator==(const Fixed& copy) const
{
    return (this->fixedPnt == copy.fixedPnt);
}

bool    Fixed::operator!=(const Fixed& copy) const
{
    return (this->fixedPnt != copy.fixedPnt);
}

/*
    -[**Arithmetic Operators**]
 */

Fixed   Fixed::operator+(const Fixed& copy) const
{
    return (Fixed(toFloat() + copy.toFloat()));
}

Fixed   Fixed::operator-(const Fixed& copy) const
{
    return (Fixed(toFloat() - copy.toFloat()));
}

Fixed   Fixed::operator*(const Fixed& copy) const
{
    return (Fixed(toFloat() * copy.toFloat()));
}

Fixed   Fixed::operator/(const Fixed& copy) const
{
    return (Fixed(toFloat() / copy.toFloat()));
}

Fixed& Fixed::operator++()
{
    fixedPnt++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    fixedPnt--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --(*this);
    return (temp);
}

Fixed Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}

std::ostream& operator<<(std::ostream& output, const Fixed& fixed)
{
    output << fixed.toFloat();
    return (output);
}
