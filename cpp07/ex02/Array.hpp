/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:51:16 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/13 21:52:26 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
	T *_elements;
	unsigned int _size;
public:
	Array(): _size(0){
		_elements = new T[0];
	}
	Array(unsigned int n): _size(n){
		_elements = new T[n]();
	}
	Array(const Array &other): _elements(NULL), _size(0){
		*this = other;
	}
	Array &operator=(const Array &other){
		if (this != &other) {
			if (_elements) {
				delete[] _elements;
			}
			_size = other._size;
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_elements[i] = other._elements[i];
			}
		}
        return *this;
	}
	~Array(){
		if (_elements) {
			delete[] _elements;
		}
	}

	T &operator[](unsigned int index){
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return _elements[index];
	}
	const T &operator[](unsigned int index) const{
		if (index >= _size) {
			throw std::out_of_range("Index out of bounds");
		}
		return _elements[index];
	}
	unsigned int size() const{
		return _size;
	}
};

#endif
