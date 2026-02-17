/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamraou <mgamraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 23:33:30 by mgamraou          #+#    #+#             */
/*   Updated: 2026/02/17 22:52:31 by mgamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>
#include <string>
#include "Bureaucrat.hpp"

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
	const int &getSignReq() const;
	const int &getExecReq() const;
	const bool &getIsSigned() const;
	void beSigned(Bureaucrat &b);
	virtual void execute(Bureaucrat const &executor) const = 0;
	class GradeTooHighException : public std::exception{
	private:
		std::string _message;
	public:
		GradeTooHighException(const std::string &message);
		virtual const char *what() const throw();
		~GradeTooHighException() throw();
	};
	class GradeTooLowException : public std::exception{
	private:
		std::string _message;
	public:
		GradeTooLowException(const std::string &message);
		virtual const char *what() const throw();
		~GradeTooLowException() throw();
	};
	class FormNotSignedException : public std::exception{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
