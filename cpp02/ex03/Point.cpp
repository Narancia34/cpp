/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:21:36 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/18 17:52:06 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(),y(){}

Point::Point(const float x, const float y):x(x),y(y){}

Point::Point(const Point& other):x(other.x), y(other.y) {}

Point& Point::operator=(const Point& other){
	(void)other;
	return *this;
}

Point::~Point(){}

Fixed Point::getX() const{
	return this->x;
}

Fixed Point::getY() const{
	return this->y;
}
