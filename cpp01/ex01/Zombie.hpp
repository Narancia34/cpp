/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:56:19 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/29 18:38:42 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string name;
public:
	Zombie();
	~Zombie();
	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde( int N, std::string name );
#endif
