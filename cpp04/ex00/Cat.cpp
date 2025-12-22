/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:34:19 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/20 11:34:22 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other){
	std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignment operator called\n";
	if (this != &other){

	}
	return (*this);
}
