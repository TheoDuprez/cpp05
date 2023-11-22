/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:39:11 by tduprez           #+#    #+#             */
/*   Updated: 2023/11/22 16:18:36 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::Bureaucrat(void): _name("Bureaucrat"), _grade(150)
{
	std::cout << "Bureaucrat constructor" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade): _name(name)
{
	std::cout << "Bureaucrat values constructor" << std::endl;
	if (static_cast<int>(grade) < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
	*this = obj;
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor" << std::endl;
	return ;
}

const std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
	return ;
}

void	Bureaucrat::signForm(const AForm& form) const
{
	try
	{
		if (form.getSignature() == true)
			std::cout << this->getName() << " signed " << form.getName() << std::endl;
		else
			throw AForm::GradeTooLowException();
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
	return ;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << "bureaucrat grade " << obj.getGrade();
	return (out);
}
