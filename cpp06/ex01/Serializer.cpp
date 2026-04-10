/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 21:13:05 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/10 22:16:48 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &other){ (void)other;}

Serializer &Serializer::operator=(const Serializer &other){
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data*>(raw);
}
