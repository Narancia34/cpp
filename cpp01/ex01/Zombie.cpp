/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:54:45 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/26 15:07:46 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	name = (*this).name;
}

void Zombie::annouce(void){
	std::cout << name << ": >: BraiiiiiiinnnzzzZ...\n";
}
