/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:40:40 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/14 16:06:22 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
	this->_value = (n << _fractionalBits);
}

Fixed::Fixed(const float n){
	this->_value = roundf(n * 256);
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = other._value;
	return *this;
}

int Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat() const{
	return (float)this->_value / 256;
}

int Fixed::toInt(void) const {
	return this->_value >> _fractionalBits;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}
