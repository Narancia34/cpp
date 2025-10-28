/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:54:45 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/28 15:40:44 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
}

void Zombie::announce(void){
	std::cout << name << ": >: BraiiiiiiinnnzzzZ...\n";
}
