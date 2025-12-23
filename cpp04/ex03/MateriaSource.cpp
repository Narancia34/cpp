/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 03:05:21 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 03:17:03 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
	for (int i = 0; i < 4; i++)
        	_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	for (int i = 0; i < 4; i++)
        	_templates[i] = NULL;
	for(int i = 0;i < 4;i++){
		if(other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other){
	if (this != &other)
	{
		for (int i = 0; i < 4; i++) {
			if (_templates[i])
				delete _templates[i];
			_templates[i] = NULL;
		}
		for (int i = 0; i < 4; i++) {
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource(){
	for (int i = 0; i < 4; i++) {
		if (_templates[i])
			delete _templates[i];
	}
}

void MateriaSource::learnMateria(AMateria *m){
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (_templates[i] == NULL) {
			_templates[i] = m;
			return;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++) {
		if (_templates[i] && _templates[i]->getType() == type)
			return _templates[i]->clone();
	}
	return 0;
}
