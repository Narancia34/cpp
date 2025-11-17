/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:21:36 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/17 19:14:26 by mgamraou         ###   ########.fr       */
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
