/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:32:09 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/23 16:32:19 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	*this = other;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string &input) {
	std::stringstream ss(input);
	std::string token;

	while (ss >> token) {
		if (token.length() > 1) {
			throw std::runtime_error("Error");
		}

		char c = token[0];
		if (isdigit(c)) {
			// Push to stack
		} else if (isOperator(c)) {
			// Perform operation
		} else {
			throw std::runtime_error("Error");
		}
	}
}
