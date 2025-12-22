/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:34:47 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/20 11:34:53 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other){
	std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignment operator called\n";
	Animal::operator=(other);
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}
