/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:10:19 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/15 17:37:04 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <vector>

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
	int shortestSpan();
	int longestSpan();
	template <typename T>
	void addRange(T begin, T end) {
		if (std::distance(begin, end) + _elements.size() > _n)
			throw SpanFullException();
		_elements.insert(_elements.end(), begin, end);
	}
	class SpanFullException : public std::exception {
	public:
		virtual const char *what() const throw(){return "Span is full";}
	};
	class NoSpanException : public std::exception {
	public: virtual const char* what() const throw() { return "Not enough numbers for a span"; }
	};
};

#endif
