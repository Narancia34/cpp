/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:10:42 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/15 17:10:55 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(): _n(){}

Span::Span(unsigned int n): _n(n){}

Span::Span(const Span &other){
	*this = other;
}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->_n = other._n;
        this->_elements = other._elements;
    }
    return *this;
}

Span::~Span(){}

void Span::addNumber(int number){
	if (_elements.size() >= _n)
		throw SpanFullException();
	_elements.push_back(number);
}

int Span::shortestSpan() {
    if (_elements.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = _elements;
    std::sort(sorted.begin(), sorted.end());

    int minDiff = sorted[1] - sorted[0];

    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int currentDiff = sorted[i + 1] - sorted[i];
        if (currentDiff < minDiff)
            minDiff = currentDiff;
    }
    return minDiff;
}

int Span::longestSpan(){
	if (_elements.size() < 2)
		throw NoSpanException();
	int minVal = *std::min_element(_elements.begin(), _elements.end());
	int maxVal = *std::max_element(_elements.begin(), _elements.end());
	return (maxVal - minVal);
}
