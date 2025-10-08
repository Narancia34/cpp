/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:38:18 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 13:47:19 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"



void PhoneBook::add(){
	std::string Inp;
	Contact Current;
	while (Inp.empty())
	{
		std::cout << "name: ";
		std::getline(std::cin, Inp);
		if (!Inp.empty()){
			Current.SetFirstName(Inp);
			break;
		}
		std::cout << "u cant have an empty field!" << std::endl;
	}
	std::cout << Current.GetFirstName();
}
