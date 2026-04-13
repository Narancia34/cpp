/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:05:50 by mgamraou          #+#    #+#             */
/*   Updated: 2026/04/13 17:17:44 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

template <typename T>

void swap(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T const &a, T const &b){
	return (a < b) ? a : b;
}

template <typename T>
T max(T const &a, T const &b){
	return (a > b) ? a : b;
}

#endif
