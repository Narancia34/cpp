/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 18:17:29 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/16 23:40:38 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include<iostream>

class Form;

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
	class GradeTooHighException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	void signForm(Form &form);
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
