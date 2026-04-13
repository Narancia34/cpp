/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:36:03 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/13 21:59:19 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
	std::cout << "--- Test 1: Basic Int Array ---" << std::endl;
	Array<int> intArray(5);
	std::cout << "Size: " << intArray.size() << std::endl;

	std::cout << "Values (should be 0): ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << "\n" << std::endl;

	std::cout << "--- Test 2: Deep Copy (Assignment) ---" << std::endl;
	Array<int> copyArray;
	intArray[0] = 42;
	copyArray = intArray;

	copyArray[0] = 100;
	std::cout << "Original [0]: " << intArray[0] << " (should be 42)" << std::endl;
	std::cout << "Copy [0]:     " << copyArray[0] << " (should be 100)" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 3: String Array & Copy Constructor ---" << std::endl;
	Array<std::string> strArray(2);
	strArray[0] = "Hello";
	strArray[1] = "42";

	Array<std::string> strCopy(strArray);
	strCopy[1] = "World";

	std::cout << "Original: " << strArray[0] << " " << strArray[1] << std::endl;
	std::cout << "Copy:     " << strCopy[0] << " " << strCopy[1] << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 4: Out of Bounds ---" << std::endl;
	try {
		std::cout << "Accessing index 10 of a size 5 array..." << std::endl;
		intArray[10] = 0;
	} catch (const std::exception& e) {
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
