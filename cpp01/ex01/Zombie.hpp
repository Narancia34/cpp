/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:56:19 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/28 15:40:54 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string name;
public:
	Zombie(std::string);
	void announce(void);
};
Zombie* newZombie( std::string name );
void randomChump( std::string name );
#endif
