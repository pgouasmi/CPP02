/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:25:46 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/16 14:54:00 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>


class Fixed {
private:
	int Number;
	static const int BitsNumber = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();

	Fixed&			operator=(const Fixed& obj);

	bool			operator<(const Fixed& obj) const;
	bool			operator>(const Fixed& obj) const;
	bool			operator>=(const Fixed& ob) const;
	bool			operator<=(const Fixed& obj) const;
	bool			operator==(const Fixed& ob);
	bool			operator!=(const Fixed& ob);

	Fixed			operator+(const Fixed& obj);
	Fixed			operator-(const Fixed& obj);


	Fixed			operator*(const Fixed& obj);
	Fixed			operator/(const Fixed& obj);

	Fixed			operator++();
	Fixed			operator++(int nb);
	Fixed			operator--();
	Fixed			operator--(int nb);

	int				getRawBits( void ) const;
	void			setRawBits( int const raw );
	float			toFloat( void ) const;
	int				toInt( void ) const;
	static Fixed	min(const Fixed& RefA, const Fixed& RefB);
	static Fixed	max(const Fixed& RefA, const Fixed& RefB);
	static Fixed	min(Fixed& RefA, Fixed& RefB);
	static Fixed	max(Fixed& RefA, Fixed& RefB);
};

std::ostream&  operator<<(std::ostream& os, const Fixed& obj);

#endif
