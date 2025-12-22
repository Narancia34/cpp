/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:53:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 17:57:38 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "wronganimal constructor called\n";
}

WrongAnimal::WrongAnimal(std::string type): _type(type){
	std::cout << "wronganimal parametrized constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	std::cout << "wronganimal copy constructor called\n";
	_type = other._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	std::cout << "wronganimal copy assignment operator called\n";
        if (this != &other){
		_type = other._type;
        }
        return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "wronganimal destructor called\n";
}

std::string WrongAnimal::getType() const{
	return _type;
}

void WrongAnimal::makeSound() const{
	std::cout << "yeeehaw" << std::endl;
}
