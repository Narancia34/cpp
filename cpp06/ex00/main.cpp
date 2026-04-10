/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:41:50 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/10 18:17:49 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void runTest(const std::string& literal) {
    std::cout << "Testing: [" << literal << "]" << std::endl;
    ScalarConverter::convert(literal);
    std::cout << "------------------------------------" << std::endl;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        ScalarConverter::convert(argv[1]);
        return 0;
    }

    std::cout << "=== SCALAR CONVERTER TEST SUITE ===" << std::endl << std::endl;

    runTest("a");
    runTest("*");

    runTest("0");
    runTest("42");
    runTest("-42");
    runTest("2147483647");

    runTest("0.0f");
    runTest("4.2f");
    runTest("-4.2f");

    runTest("0.0");
    runTest("42.42");
    runTest("-42.42");

    runTest("nan");
    runTest("nanf");
    runTest("+inf");
    runTest("-inff");

    runTest("2147483648");
    runTest("999");
    runTest("33");
    runTest("127");

    return 0;
}
