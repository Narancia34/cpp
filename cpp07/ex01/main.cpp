/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 18:12:42 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/13 18:15:12 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Iter.hpp"

void increment(int &n) {
	n++;
}

template <typename T>
void printElement(T const &item) {
	std::cout << item << " ";
}

int main() {
	std::cout << "Test 1: Integer array increment" << std::endl;
	int intArr[] = {0, 1, 2, 3, 4};
	size_t intLen = 5;

	::iter(intArr, intLen, printElement<int>);
	std::cout << std::endl;

	::iter(intArr, intLen, increment);
	std::cout << "After increment: ";
	::iter(intArr, intLen, printElement<int>);
	std::cout << "\n" << std::endl;


	std::cout << "Test 2: String array" << std::endl;
	std::string strArr[] = {"Hello", "world", "!"};

	::iter(strArr, 3, printElement<std::string>);
	std::cout << "\n" << std::endl;


	std::cout << "Test 3: Const Integer array" << std::endl;
	const int constArr[] = {42, 21, 84};

	::iter(constArr, 3, printElement<int>);
	std::cout << "\n" << std::endl;

	return 0;
}
