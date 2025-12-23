/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:28:37 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 01:45:26 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice"){}

Ice::Ice(const Ice &other) : AMateria(other){}

Ice &Ice::operator=(const Ice &other){
	AMateria::operator=(other);
	return *this;
}

Ice::~Ice(){}

Ice *Ice::clone() const{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots ice bolt at *\n";
	(void)target;
}
