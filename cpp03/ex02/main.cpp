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

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main(){
	ScavTrap a("taha");
	a.guardGate();
	a.takeDamage(20);
	a.ClapTrap::attack("test");
	a.attack("test2");
	ScavTrap b;
}
