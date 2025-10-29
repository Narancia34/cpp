/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:31:27 by mgamraou          #+#    #+#             */
/*   Updated: 2025/10/29 18:20:41 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    const int N = 5;
    Zombie* horde = zombieHorde(N, "HordeZombie");
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    delete[] horde;

    return 0;
}