/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:34:47 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 20:46:02 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog constructor called\n";
	_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other){
	std::cout << "Dog copy constructor called\n";
	_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other){
	std::cout << "Dog copy assignment operator called\n";
	Animal::operator=(other);
	if (this != &other){
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "Dog destructor called\n";
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "woof woof" << std::endl;
}
