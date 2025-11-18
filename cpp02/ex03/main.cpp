/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:21:26 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/18 18:06:35 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

void testTriangle(Point a, Point b, Point c, std::string name) {
    std::cout << "\n=== Testing Triangle: " << name << " ===" << std::endl;
    std::cout << "A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << std::endl;
}

void testPoint(Point a, Point b, Point c, Point p, std::string description, bool expected) {
    bool result = bsp(a, b, c, p);
    std::cout << description << " (" << p.getX() << ", " << p.getY() << "): " 
              << (result ? "INSIDE" : "OUTSIDE");
    
    if (result == expected) {
        std::cout << " ✓" << std::endl;
    } else {
        std::cout << " ✗ (Expected: " << (expected ? "INSIDE" : "OUTSIDE") << ")" << std::endl;
    }
}

int main() {
    std::cout << "=== BSP (Binary Space Partitioning) Tests ===" << std::endl;
    
    // Test 1: Right triangle with vertices at (0,0), (4,0), (0,3)
    Point a1(0.0f, 0.0f);
    Point b1(4.0f, 0.0f);
    Point c1(0.0f, 3.0f);
    
    testTriangle(a1, b1, c1, "Right Triangle");
    
    // Points that should be INSIDE
    testPoint(a1, b1, c1, Point(1.0f, 1.0f), "Center point", true);
    testPoint(a1, b1, c1, Point(0.5f, 0.5f), "Near vertex A", true);
    testPoint(a1, b1, c1, Point(2.0f, 0.5f), "Near edge AB", true);
    testPoint(a1, b1, c1, Point(1.5f, 1.0f), "Inside triangle", true);
    
    // Points that should be OUTSIDE (vertices)
    testPoint(a1, b1, c1, Point(0.0f, 0.0f), "Vertex A", false);
    testPoint(a1, b1, c1, Point(4.0f, 0.0f), "Vertex B", false);
    testPoint(a1, b1, c1, Point(0.0f, 3.0f), "Vertex C", false);
    
    // Points that should be OUTSIDE (on edges)
    testPoint(a1, b1, c1, Point(2.0f, 0.0f), "On edge AB", false);
    testPoint(a1, b1, c1, Point(0.0f, 1.5f), "On edge AC", false);
    testPoint(a1, b1, c1, Point(2.0f, 1.5f), "On edge BC", false);
    
    // Points that should be OUTSIDE (completely outside)
    testPoint(a1, b1, c1, Point(-1.0f, 0.0f), "Left of triangle", false);
    testPoint(a1, b1, c1, Point(5.0f, 0.0f), "Right of triangle", false);
    testPoint(a1, b1, c1, Point(0.0f, 4.0f), "Above triangle", false);
    testPoint(a1, b1, c1, Point(2.0f, -1.0f), "Below triangle", false);
    testPoint(a1, b1, c1, Point(3.0f, 2.0f), "Outside hypotenuse", false);
    
    // Test 2: Equilateral-ish triangle
    Point a2(0.0f, 0.0f);
    Point b2(6.0f, 0.0f);
    Point c2(3.0f, 5.0f);
    
    testTriangle(a2, b2, c2, "Isosceles Triangle");
    
    testPoint(a2, b2, c2, Point(3.0f, 2.0f), "Center point", true);
    testPoint(a2, b2, c2, Point(1.5f, 1.0f), "Left side", true);
    testPoint(a2, b2, c2, Point(4.5f, 1.0f), "Right side", true);
    testPoint(a2, b2, c2, Point(3.0f, 0.5f), "Bottom center", true);
    
    // On edges/vertices (should be false)
    testPoint(a2, b2, c2, Point(3.0f, 0.0f), "Midpoint of base", false);
    testPoint(a2, b2, c2, Point(1.5f, 2.5f), "On left edge", false);
    testPoint(a2, b2, c2, Point(4.5f, 2.5f), "On right edge", false);
    
    // Outside
    testPoint(a2, b2, c2, Point(3.0f, 6.0f), "Above apex", false);
    testPoint(a2, b2, c2, Point(-1.0f, 2.0f), "Far left", false);
    testPoint(a2, b2, c2, Point(7.0f, 2.0f), "Far right", false);
    
    // Test 3: Thin triangle (edge case)
    Point a3(0.0f, 0.0f);
    Point b3(10.0f, 0.0f);
    Point c3(5.0f, 0.1f);  // Very thin triangle
    
    testTriangle(a3, b3, c3, "Thin Triangle");
    
    testPoint(a3, b3, c3, Point(5.0f, 0.05f), "Inside thin triangle", true);
    testPoint(a3, b3, c3, Point(2.5f, 0.025f), "Left side inside", true);
    testPoint(a3, b3, c3, Point(7.5f, 0.025f), "Right side inside", true);
    
    // On edge of thin triangle
    testPoint(a3, b3, c3, Point(5.0f, 0.0f), "On base", false);
    testPoint(a3, b3, c3, Point(5.0f, 0.1f), "At apex", false);
    
    // Test 4: Negative coordinates
    Point a4(-2.0f, -2.0f);
    Point b4(2.0f, -2.0f);
    Point c4(0.0f, 2.0f);
    
    testTriangle(a4, b4, c4, "Triangle with Negative Coordinates");
    
    testPoint(a4, b4, c4, Point(0.0f, 0.0f), "Origin point", true);
    testPoint(a4, b4, c4, Point(-0.5f, -0.5f), "Negative quadrant", true);
    testPoint(a4, b4, c4, Point(0.5f, -0.5f), "Mixed coordinates", true);
    
    // Test 5: Degenerate triangle (collinear points)
    Point a5(0.0f, 0.0f);
    Point b5(2.0f, 0.0f);
    Point c5(4.0f, 0.0f);  // All points on same line
    
    testTriangle(a5, b5, c5, "Degenerate Triangle (Collinear)");
    
    testPoint(a5, b5, c5, Point(1.0f, 0.0f), "On line", false);
    testPoint(a5, b5, c5, Point(2.0f, 1.0f), "Above line", false);
    testPoint(a5, b5, c5, Point(2.0f, -1.0f), "Below line", false);
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}