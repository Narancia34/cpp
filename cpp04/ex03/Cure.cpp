/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:38:42 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 02:24:12 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure"){}

Cure::Cure(const Cure &other) : AMateria(other){}

Cure &Cure::operator=(const Cure &other){
	AMateria::operator=(other);
	return *this;
}

Cure::~Cure(){}

Cure *Cure::clone() const{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target){
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
