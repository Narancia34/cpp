/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:59:07 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/14 17:25:05 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"
#include <iomanip>
#include <iostream>
#include <stdlib.h>

class PhoneBook {
private:
	Contact Contacts[8];
	int index;
public:
	void add();
	void search();
	void SetIndex(int Value);
};

std::string getinfo(std::string Prompt);
#endif
