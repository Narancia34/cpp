/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:34:19 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 21:02:33 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat constructor called\n";
	_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other){
	std::cout << "Cat copy constructor called\n";
	_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other){
	std::cout << "Cat copy assignment operator called\n";
	Animal::operator=(other);
	if (this != &other){
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat destructor called\n";
	delete _brain;
}

void Cat::makeSound() const {
	std::cout << "meow" << std::endl;
}

void Cat::fillBrain(std::string ideas[]){
	this->_brain->think(ideas);
}
