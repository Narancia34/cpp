/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:01:40 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/15 17:08:20 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <vector>

int main() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);

	std::vector<int>::iterator it = easyfind(v, 10);
	if (it != v.end())
		std::cout << "found: " << *it << std::endl;
	else
		std::cout << "not found" << std::endl;
	it = easyfind(v, 99);
	if (it != v.end())
		std::cout << "found: " << *it << std::endl;
	else
		std::cout << "not found" << std::endl;
	return 0;
}
