/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:21:11 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/15 15:20:28 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	Fixed a( 1.1f );
	Fixed const b( 1.11f );
	/*Fixed const c( 42.42f );*/
	if (b==a)
		std::cout << "b==a"<< std::endl;
	if (b>a)
		std::cout << "b>a"<< std::endl;
	if (b<a)
		std::cout << "b<a"<< std::endl;
	if (b!=a)
		std::cout << "b!=a"<< std::endl;
	std::cout << a << std::endl;
	return 0;
}
