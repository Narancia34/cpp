/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:10:19 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/17 18:29:20 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <iostream>

class Span{
private:
	unsigned int _n;
	std::vector<int> _elements;
	Span();
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	template <typename T>
	void addRange(T begin, T end) {
		if (std::distance(begin, end) + _elements.size() > _n)
			throw SpanFullException();
		_elements.insert(_elements.end(), begin, end);
	}
	class SpanFullException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NoSpanException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif
