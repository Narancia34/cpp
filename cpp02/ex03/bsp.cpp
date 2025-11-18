/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:21:20 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/18 18:06:13 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const p1, Point const p2, Point const p3){
    Fixed a = (p1.getX() * (p2.getY() - p3.getY()));
    Fixed b = (p2.getX() * (p3.getY() - p1.getY()));
    Fixed c = (p3.getX() * (p1.getY() - p2.getY()));
    Fixed area = (a + b + c) / Fixed(2);
    if (area < Fixed(0))
        area = area * Fixed(-1);
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
    Fixed totalArea = area(a, b, c);
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);
    if (area1 == Fixed(0) || area2 == Fixed(0) || area3 == Fixed(0))
        return false;
    return (totalArea == area1 + area2 + area3);
}