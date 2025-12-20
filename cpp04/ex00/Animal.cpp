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
	std::cout << "animal constructer called\n";
}

Animal::Animal(const Animal &other){
	std::cout << "animal copy constructer called\n";
}

Animal &Animal::operator=(const Animal &other){
	std::cout << "animal copy assignment operator called\n";
        if (this != &other){
		type = other.type;
        }
        return (*this);
}

Animal::~Animal(){}
