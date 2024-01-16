/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:25:46 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/16 14:59:23 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default Constructor called" << std::endl;
	Number = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int nb)
{
	// std::cout << "Int constructor called" << std::endl;
	Number = nb * (1 << BitsNumber);
}

Fixed::Fixed(const float nb)
{

	// std::cout << "Float constructor called" << std::endl;
	Number = roundf(nb * (1 << BitsNumber));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}






Fixed& Fixed::operator=(const Fixed& obj)
{
	// std::cout << "Copy assignment called" << std::endl;
	Number = obj.getRawBits();
	return *this;
}

std::ostream&  operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

bool  Fixed::operator<(const Fixed& obj) const
{
	return (this->getRawBits() < obj.getRawBits()) ? true : false;
}

bool  Fixed::operator<=(const Fixed& obj) const
{
	return (this->Number <= obj.getRawBits()) ? true : false;
}

bool  Fixed::operator>(const Fixed& obj) const
{
	return (obj.getRawBits() > obj.getRawBits()) ? true : false;
}

bool  Fixed::operator>=(const Fixed& obj) const
{
	return (obj.getRawBits() >= obj.getRawBits()) ? true : false;
}

bool  Fixed::operator!=(const Fixed& obj)
{
	return (obj.getRawBits() != obj.getRawBits()) ? true : false;
}

bool  Fixed::operator==(const Fixed& obj)
{
	return (obj.getRawBits() == obj.getRawBits()) ? true : false;
}

Fixed  Fixed::operator+(const Fixed& obj)
{
	return (Fixed((this->toFloat()) + (obj.toFloat())));
}

Fixed  Fixed::operator-(const Fixed& obj)
{
	return (Fixed((this->toFloat()) - (obj.toFloat())));
}

Fixed  Fixed::operator*(const Fixed& obj)
{
	return (Fixed((this->toFloat()) * (obj.toFloat())));
}

Fixed  Fixed::operator/(const Fixed& obj)
{
	std::cout << "in /, result = " << this->toFloat() << "/" << obj.toFloat() << std::endl;
	return (Fixed((this->toFloat()) / (obj.toFloat())));
}

Fixed Fixed::operator++()
{
	Number++;
	return *this;
}

Fixed Fixed::operator++(int nb)
{
	(void)nb;
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed Fixed::operator--()
{
	Number--;
	return *this;
}

Fixed Fixed::operator--(int nb)
{
	(void)nb;
	Fixed tmp(*this);
	operator--();
	return tmp;
}

int Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (Number);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	Number = raw;
}

int		Fixed::toInt() const
{
	return Number >> BitsNumber;
}

float	Fixed::toFloat() const
{
	return (float)Number / 256.0f;
}

Fixed Fixed::min(const Fixed& RefA, const Fixed& RefB)
{
	if (RefA < RefB)
		return (RefA);
	return (RefB);

}

Fixed Fixed::max(const Fixed& RefA, const Fixed& RefB)
{
	if (RefA > RefB)
		return (RefA);
	return (RefB);
}

Fixed Fixed::min(Fixed& RefA, Fixed& RefB)
{
	if (RefA < RefB)
		return (RefA);
	return (RefB);

}

Fixed Fixed::max(Fixed& RefA, Fixed& RefB)
{
	if (RefA > RefB)
		return (RefA);
	return (RefB);
}




