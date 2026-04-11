/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:54:52 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/11 17:18:28 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){};

Base *generate(){
	int i = std::rand() % 3;
	if (i == 0)
		return new A();
	else if (i == 1)
		return new B();
	else
		return new C();
}

void identify(Base *p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p){
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	} catch (std::exception &e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	} catch (std::exception &e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	} catch (std::exception &e) {}
}
