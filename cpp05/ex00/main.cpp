/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 22:47:28 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/16 22:48:56 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    // --- Test 1: Perfect Bureaucrat ---
    std::cout << "--- Test 1: Standard Creation ---" << std::endl;
    try {
        Bureaucrat bob(2, "Bob");
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 2: Grade Too High (Constructor) ---" << std::endl;
    try {
        Bureaucrat high(0, "HighFlyer"); // Should throw
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 3: Grade Too Low (Constructor) ---" << std::endl;
    try {
        Bureaucrat low(151, "LowLifer"); // Should throw
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 4: Incrementing into Exception ---" << std::endl;
    try {
        Bureaucrat top(1, "CEO");
        std::cout << top << std::endl;
        top.incrementGrade(); // Should throw (1 -> 0)
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    std::cout << "\n--- Test 5: Decrementing into Exception ---" << std::endl;
    try {
        Bureaucrat bottom(150, "Intern");
        std::cout << bottom << std::endl;
        bottom.decrementGrade(); // Should throw (150 -> 151)
    } catch (std::exception &e) {
        std::cerr << "Caught expected error: " << e.what() << std::endl;
    }

    return 0;
}
