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

bool RPN::isOperator(const char c) const {
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(const char c){
	if (this->_stack.size() < 2) {
		throw std::runtime_error("Error");
	}

	int rhs = this->_stack.top();
	this->_stack.pop();

	int lhs = this->_stack.top();
	this->_stack.pop();

	if (c == '+') this->_stack.push(lhs + rhs);
	else if (c == '-') this->_stack.push(lhs - rhs);
	else if (c == '*') this->_stack.push(lhs * rhs);
	else if (c == '/') {
		if (rhs == 0) throw std::runtime_error("Error");
		this->_stack.push(lhs / rhs);
	}
}

void RPN::calculate(const std::string &input) {
	std::stringstream ss(input);
	std::string token;

	while (ss >> token) {
		if (token.length() > 1) {
			throw std::runtime_error("Error");
		}

		char c = token[0];
		if (isdigit(c)) {
			this->_stack.push(c - '0');
		} else if (isOperator(c)) {
			performOperation(c);
		} else {
			throw std::runtime_error("Error");
		}
	}
	if (this->_stack.size() != 1) {
		throw std::runtime_error("Error");
	}
	std::cout << this->_stack.top() << std::endl;
}
