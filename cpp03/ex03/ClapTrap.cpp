/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:06:04 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/28 16:09:33 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hp(10), _energy(10), _dmg(){
	std::cout << "ClapTrap parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int energy, int dmg): _name(name), _hp(hp), _energy(energy), _dmg(dmg){
	std::cout << "ClapTrap special parameterized constructor called" << std::endl;
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

void ClapTrap::attack(const std::string& target){
	if (this->_energy <= 0){
		std::cout << "energy too low to attack !" << std::endl;
		return;
	}
	this->_energy--;
	std::cout << "ClapTrap " << this->_name
		<< " attacks " << target
		<< ", causing " << this->_dmg
		<< " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount > this->_hp)
		amount = this->_hp;
	if (this->_hp == 0){
		std::cout << "ClapTrap " << this->_name
			<< " is already dead" << std::endl;
		return;
	}
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name
		<< " lost " << amount
		<< " health points !" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energy <= 0){
		std::cout << "energy too low to be repaired !" << std::endl;
		return;
	}
	this->_energy--;
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name
		<< " gained " << amount
		<< " health points" << std::endl;
}
