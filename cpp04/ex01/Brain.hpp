/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:04:13 by mgamraou          #+#    #+#             */
/*   Updated: 2025/12/22 20:50:57 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
private:
	std::string _ideas[100];
public:
	Brain();
	Brain(std::string ideas[]);
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();
	void think(std::string ideas[]);
};

#endif
