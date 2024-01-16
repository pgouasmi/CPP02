/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:25:46 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/16 12:49:42 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	Number = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	Number = roundf(nb * (1 << BitsNumber));
}

Fixed::Fixed(const float nb)
{

	std::cout << "Float constructor called" << std::endl;
	Number = roundf(nb * (1 << BitsNumber));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}



Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment called" << std::endl;
	Number = obj.getRawBits();
	return *this;
}

std::ostream&  operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (Number);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	Number = raw;
}

int		Fixed::toInt() const
{
	return Number / 256;
}

float	Fixed::toFloat() const
{
	return (float)Number / 256.0f;
}


