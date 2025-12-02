/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:55:07 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/02 17:03:26 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(){
	FragTrap a("taha");
	ClapTrap b("nara");
	ScavTrap c("mohamed");
	a.attack("someone");
	b.attack("lol");
	c.attack("bleh");
	a.highFivesGuys();
	c.guardGate();
	FragTrap d(a);
	d.attack("idk");
	d.takeDamage(90);
}
