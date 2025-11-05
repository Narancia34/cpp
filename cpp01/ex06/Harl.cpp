/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:46:41 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/05 18:00:12 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


void Harl::debug(void){
	std::cout << "[ DEBUG ]\n"
		 "I love having extra bacon for my 7XL-double-cheese-"
		 "triple-pickle-special-ketchup burger. I really do!"
		 << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]\n"
		"I cannot believe adding extra bacon costs more money."
		" You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]\n"
		"I think I deserve to have some extra bacon for free."
		"I’ve been coming for years, whereas you started working here just last month."
		<< std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]\n"
		"This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level){
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*fcnPtr[4])(void) = {&Harl::debug,
					&Harl::info,
					&Harl::warning,
					&Harl::error};
	int i;
	for (i = 0; i < 4; i++){
		if(levels[i] == level)
			break;
	}
	switch (i){
		case 0:
			(this->*fcnPtr[0])();
		case 1:
			(this->*fcnPtr[1])();
		case 2:
			(this->*fcnPtr[2])();
		case 3:
			(this->*fcnPtr[3])();
			return ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" <<  std::endl;
	}
}
