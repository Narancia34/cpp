/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:11:58 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/29 18:12:47 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    if (N <= 0)
        return nullptr;
    
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        horde[i] = Zombie(name);
    }
    return horde;
}