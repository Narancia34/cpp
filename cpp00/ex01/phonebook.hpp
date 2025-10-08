/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:59:07 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/08 12:31:01 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

class PhoneBook {
private:
	Contact Contacts[8];
public:
	void add();
	void search();
};
