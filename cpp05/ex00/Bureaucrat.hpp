/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:17:29 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/15 18:34:31 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include<iostream>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(int grade, const std::string &name);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();
	const std::string &getName() const;
	const int &getGrade() const;
	void incrementGrade();
	void decrementGrade();
};
#endif
