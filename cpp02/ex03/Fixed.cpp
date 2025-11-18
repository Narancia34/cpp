/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:21:09 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/18 18:08:06 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(): _value(){}

Fixed::Fixed(const int n){
	this->_value = (n << _fractionalBits);
}

Fixed::Fixed(const float n){
	this->_value = roundf(n * 256);
}

Fixed::Fixed(const Fixed& other){
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other){
	this->_value = other._value;
	return *this;
}

int Fixed::getRawBits() const{
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

float Fixed::toFloat() const{
	return (float)this->_value / 256;
}

int Fixed::toInt(void) const {
	return this->_value >> _fractionalBits;
}

Fixed::~Fixed(){
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

Fixed& Fixed::min(Fixed& p1, Fixed&p2){
	if (p1 > p2)
		return p2;
	else
		return p1;
}
Fixed& Fixed::max(Fixed& p1, Fixed&p2){
	if (p1 > p2)
		return p1;
	else
		return p2;
}
Fixed& Fixed::min(const Fixed& p1, const Fixed&p2){
	if (p1 > p2)
		return (Fixed&)p2;
	else
		return (Fixed&)p1;
}
Fixed& Fixed::max(const Fixed& p1, const Fixed&p2){
	if (p1 > p2)
		return (Fixed&)p1;
	else
		return (Fixed&)p2;
}
