/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 23:10:43 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/23 03:22:42 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	/*IMateriaSource* src = new MateriaSource();*/
	/*src->learnMateria(new Ice());*/
	/*src->learnMateria(new Cure());*/
	/*ICharacter* me = new Character("me");*/
	/*AMateria* tmp;*/
	/*tmp = src->createMateria("ice");*/
	/*me->equip(tmp);*/
	/*tmp = src->createMateria("cure");*/
	/*me->equip(tmp);*/
	/*ICharacter* bob = new Character("bob");*/
	/*me->use(0, *bob);*/
	/*me->use(1, *bob);*/
	/*delete bob;*/
	/*delete me;*/
	/*delete src;*/
	std::cout << "--- TEST 1: BASICS & EQUIP ---" << std::endl;
	Character* me = new Character("me");
	Character* bob = new Character("bob");

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	me->equip(ice);
	me->equip(cure);

	std::cout << "Should print ice/cure messages:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	std::cout << "\n--- TEST 2: DEEP COPY ---" << std::endl;
	Character* meClone = new Character(*me);

	std::cout << "Original uses Ice:" << std::endl;
	me->use(0, *bob); 

	std::cout << "Clone uses Ice:" << std::endl;
	meClone->use(0, *bob);

	std::cout << ">> Unequipping slot 0 from Original only..." << std::endl;
	me->unequip(0);

	std::cout << "Clone using slot 0 (Should still work): ";
	meClone->use(0, *bob);

	std::cout << "Original using slot 0 (Should do nothing):   ";
	me->use(0, *bob);

	std::cout << "\n--- TEST 3: UNEQUIP & MEMORY ---" << std::endl;
	me->unequip(0);
	me->unequip(1);

	me->use(0, *bob);

	std::cout << "\n--- CLEANUP ---" << std::endl;

	delete me;
	delete meClone;
	delete bob;

	delete ice; 
	delete cure;

	return 0;
	return 0;
}
