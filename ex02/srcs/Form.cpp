/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:24:26 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 17:34:52 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

Form::Form(void): _name("Form"), _requireGradeToSign(1), _requireGradeToExecute(15)
{
	std::cout << "Form constructor" << std::endl;
	return ;
}

Form::Form(const std::string name, const unsigned int requireGradeToSign, const unsigned int requireGradeToExecute): \
_name(name), _signature(false), _requireGradeToSign(requireGradeToSign), _requireGradeToExecute(requireGradeToExecute)
{
	std::cout << "Form values constructor" << std::endl;
	return ;
}

Form::Form(const Form& obj): _requireGradeToSign(obj.getRequireGradeToSign()), _requireGradeToExecute(obj.getRequireGradeToExecute())
{
	std::cout << "Form copy constructor" << std::endl;
	*this = obj;
	return ;
}

Form&	Form::operator=(const Form& obj)
{
	if (this != &obj)
		this->_signature = obj._signature;
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form destructor" << std::endl;
	return ;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->_requireGradeToSign < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	else
		this->_signature = true;
	return ;
}

unsigned int	Form::getRequireGradeToSign(void) const
{
	return this->_requireGradeToSign;
}

unsigned int	Form::getRequireGradeToExecute(void) const
{
	return this->_requireGradeToExecute;
}

const std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::getSignature(void) const
{
	return this->_signature;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& out, const Form& obj)
{
	out << "Name is : " << obj.getName() << std::endl;
	out << "The form is signed : " << obj.getSignature() << std::endl;
	out << "Require grade to sign : " << obj.getRequireGradeToSign() << std::endl;
	out << "Required grade to execute : " << obj.getRequireGradeToExecute();
	return (out);
}
