/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:24:46 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/02 17:00:56 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "ScavTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30) {
	std::cout << "FragTrap parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other){
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other){
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
        return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "FragTrap requests high-fives" << std::endl;
}
