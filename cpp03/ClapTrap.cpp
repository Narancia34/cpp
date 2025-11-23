/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:06:04 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/23 15:18:11 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

ClapTrap::ClapTrap(std::string name): _hp(10), _dmg(), _energy(10), _name(name){
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
	this->_name = other._name;
	this->_dmg = other._dmg;
	this->_energy = other._energy;
	this->_hp = other._hp;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	if (this != &other){
		this->_name = other._name;
		this->_dmg = other._dmg;
		this->_energy = other._energy;
		this->_hp = other._hp;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
}
