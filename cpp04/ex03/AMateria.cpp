/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:34:20 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 01:36:50 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type){}

AMateria::AMateria(const AMateria &other){
	_type = other._type;
}

AMateria &AMateria::operator=(const AMateria &other){
	if (this != &other){
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria(){}

std::string const &AMateria::getType() const{
	return _type;
}

void AMateria::use(ICharacter&target){
	(void)target;
}
