/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgouasmi <pgouasmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:24:43 by pgouasmi          #+#    #+#             */
/*   Updated: 2024/01/16 14:57:10 by pgouasmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

int	main( void )
{
	Fixed		a;
	Fixed const b(Fixed( 5.05f ) * Fixed(2));

	if (a < b)
		std::cout << "a < b" <<std::endl;
	Fixed c(5);
	Fixed d(5);

	if (c == d)
		std::cout << "c == d" << std::endl;
	if (c >= d)
		std::cout << "c >= d" << std::endl;
	if (c < d)
		std::cout << "c < d" << std::endl;
	if (c <= d)
		std::cout << "c <= d" << std::endl;

	Fixed e(c / d);
	Fixed f(69.0f / 42.0f);
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << a <<std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b <<std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
