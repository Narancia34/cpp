/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:26:01 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/20 11:31:23 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	std::cout << "animal constructor called\n";
}

Animal::Animal(std::string type): _type(type){
	std::cout << "animal parametrized constructor called\n";
}

Animal::Animal(const Animal &other){
	std::cout << "animal copy constructor called\n";
	_type = other._type;
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "animal copy assignment operator called\n";
        if (this != &other){
		_type = other._type;
        }
        return (*this);
}

Animal::~Animal(){
	std::cout << "animal destructor called\n";
}

std::string Animal::getType() const{
	return _type;
}

void Animal::makeSound() const{
	std::cout << "yeeehaw" << std::endl;
}
