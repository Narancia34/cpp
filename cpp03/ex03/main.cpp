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

#include "DiamondTrap.hpp"

int main(){
	DiamondTrap a("skibidi");
	a.attack("someone");
	a.ClapTrap::attack("idk");
	a.whoAmI();
	a.beRepaired(10);
	a.highFivesGuys();
	a.guardGate();
	a.takeDamage(20);
	a.beRepaired(20);
}
