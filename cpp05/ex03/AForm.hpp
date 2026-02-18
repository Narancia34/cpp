/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:33:30 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/18 17:33:56 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include<iostream>
#include <string>

class AForm{
private:
	const std::string _name;
	bool _isSigned;
	const int _signReq;
	const int _execReq;
public:
	AForm();
	AForm(const std::string& name, int signReq, int execReq);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	const std::string &getName() const;
	int getSignReq() const;
	int getExecReq() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
