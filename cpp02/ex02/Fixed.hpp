/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:20:02 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/15 15:14:34 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
private:
	int _value;
	static const int _fractionalBits;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
	bool operator==(const Fixed& rFixed) const;
	bool operator!=(const Fixed& rFixed) const;
	bool operator<=(const Fixed& rFixed) const;
	bool operator>=(const Fixed& rFixed) const;
	bool operator>(const Fixed& rFixed) const;
	bool operator<(const Fixed& rFixed) const;
	Fixed operator+(const Fixed& rFixed) const;
	Fixed operator-(const Fixed& rFixed) const;
	Fixed operator*(const Fixed& rFixed) const;
	Fixed operator/(const Fixed& rFixed) const;
	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif
