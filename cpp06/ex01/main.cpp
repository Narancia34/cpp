/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:30:44 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/10 22:16:29 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main() {
	Data myData = {42, "mgamraou"};
	Data* originalPtr = &myData;
	uintptr_t raw = Serializer::serialize(originalPtr);
	Data* resultPtr = Serializer::deserialize(raw);
	if (resultPtr == originalPtr) {
		std::cout << "Success! Pointers match." << std::endl;
		std::cout << "username:" << resultPtr->username << "\nid: " << resultPtr->id << std::endl;
	} else {
		std::cout << "Error: Pointers do not match!" << std::endl;
	}
}
