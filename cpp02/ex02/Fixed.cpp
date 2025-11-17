/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:20:30 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/15 15:15:06 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n){
	std::cout << "int constructor called" << std::endl;
	this->_value = (n << _fractionalBits);
}

Fixed::Fixed(const float n){
	std::cout << "float constructor called" << std::endl;
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


std::ostream& operator<<(std::ostream& out, const Fixed& fixed){
	float fn = fixed.toFloat();
	out << fn;
	return out;
}

bool Fixed::operator==(const Fixed& rFixed) const{
	return this->_value == rFixed._value;
}
bool Fixed::operator!=(const Fixed& rFixed) const{
	return this->_value != rFixed._value;
}
bool Fixed::operator<=(const Fixed& rFixed) const{
	return this->_value <= rFixed._value;
}
bool Fixed::operator>=(const Fixed& rFixed) const{
	return this->_value >= rFixed._value;
}
bool Fixed::operator>(const Fixed& rFixed) const{
	return this->_value > rFixed._value;
}
bool Fixed::operator<(const Fixed& rFixed) const{
	return this->_value < rFixed._value;
}


Fixed Fixed::operator+(const Fixed& rFixed) const{
	return Fixed(this->toFloat() + rFixed.toFloat());
}
Fixed Fixed::operator-(const Fixed& rFixed) const{
	return Fixed(this->toFloat() - rFixed.toFloat());
}
Fixed Fixed::operator*(const Fixed& rFixed) const{
	return Fixed(this->toFloat() * rFixed.toFloat());
}
Fixed Fixed::operator/(const Fixed& rFixed) const{
	return Fixed(this->toFloat() / rFixed.toFloat());
}

Fixed& Fixed::operator++(){
	this->_value++;
	return(*this);
}
Fixed& Fixed::operator--(){
	this->_value--;
	return(*this);
}
Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	this->_value++;
	return(tmp);
}
Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	this->_value--;
	return(tmp);
}
