/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:28:52 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/17 18:36:56 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <exception>
#include <ctime>
#include <cstdlib>

int main() {
	std::cout << "--- Subject Test ---" << std::endl;
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n--- Exception Tests ---" << std::endl;
	try {
		Span small(1);
		small.addNumber(42);
		std::cout << small.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	try {
		Span full(2);
		full.addNumber(1);
		full.addNumber(2);
		full.addNumber(3);
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n--- 10,000 Numbers Test ---" << std::endl;
	try {
		Span big(10000);
		std::vector<int> randomNums;

		std::srand(std::time(NULL));
		for (int i = 0; i < 10000; ++i) {
			randomNums.push_back(std::rand());
		}

		big.addRange(randomNums.begin(), randomNums.end());

		std::cout << "Shortest: " << big.shortestSpan() << std::endl;
		std::cout << "Longest:  " << big.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
