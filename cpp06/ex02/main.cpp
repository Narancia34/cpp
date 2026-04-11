/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:08:48 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/11 17:19:10 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(){
	std::srand(std::time(NULL));
	Base *p = generate();
	identify(p);
	Base *p1 = generate();
	identify(*p1);
}
