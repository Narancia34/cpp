/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:08:58 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 19:26:38 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain constructor called\n";
}

Brain::Brain(std::string ideas[]){
	std::cout << "Brain parameterized constructor called\n";
	for (int i = 0;i<100;i++){
		_ideas[i] = ideas[i];}
}

Brain::Brain(const Brain &other){
	std::cout << "Brain copy constructor called\n";
	for(int i = 0;i<100;i++){
		_ideas[i] = other._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other){
	std::cout << "Brain copy assignment operator called\n";
	if (this != &other){
		for(int i = 0;i<100;i++){
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "Brain destructor called\n";
}
