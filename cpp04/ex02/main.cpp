/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:32:29 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 21:26:06 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Cat* cat1= new Cat();
	std::string ideas[100];
	for(int i = 0;i < 100;i++){
		ideas[i] = "mouse";
	}
	std::string ideas1[100];
	for(int i = 0;i < 100;i++){
		ideas[i] = "mouse1";
	}
	cat1->fillBrain(ideas);
	Cat* cat2 = new Cat();
	cat2->fillBrain(ideas1);
	*cat2 = *cat1;
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();
	Animal* animals[4];

	animals[0] = cat1;
	animals[1] = cat2;
	animals[2] = dog1;
	animals[3] = dog2;
	animals[0]->makeSound();
	animals[1]->makeSound();
	animals[2]->makeSound();
	animals[3]->makeSound();
	std::cout << "\n-------------Destrcution here-------------\n\n";
	for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
}
