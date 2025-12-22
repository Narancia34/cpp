/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 18:00:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 18:01:32 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	std::cout << "WrongCat copy assignment operator called\n";
	WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const {
	std::cout << "meow" << std::endl;
}
