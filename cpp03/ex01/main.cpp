/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:55:07 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/28 16:09:03 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Claptrap.hpp"

int main(){
	ClapTrap a("a");
	a.takeDamage(12);
	a.takeDamage(1);
	a.beRepaired(8);
	a.takeDamage(7);
	for (int i = 0; i < 10; i++){
		a.attack("someone");
	}
}
