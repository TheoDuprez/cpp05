/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 00:02:23 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/15 00:04:04 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

static bool	isGoodForm(const std::string formName, const std::string formTest);

Intern::Intern(void)
{
	std::cout << "Intern constructor" << std::endl;
	return ;
}

Intern::Intern(const Intern& obj)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = obj;
	return ;
}

Intern&	Intern::operator=(const Intern& obj)
{
	(void)obj;
	return *this;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor" << std::endl;
	return ;
}

AForm*	createShruberry(const std::string target)
{
	return (new ShruberryCreationForm(target));
}

AForm*	createRobotomyRequest(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	createPresidentialPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string formName, const std::string target) const
{
	AForm* (*ptr[3])(const std::string target) = {&createShruberry, &createRobotomyRequest, &createPresidentialPardon};
	std::string		forms[3] = { "Shruberry", "Robotomy", "Presidential" };

	for (int i = 0; i < 3; i++)
	{
		if (isGoodForm(formName, forms[i]) == true)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (ptr[i](target));
		}
	}
	throw Intern::BadFormException();
	return NULL;
}

const char*	Intern::BadFormException::what() const throw()
{
	return ("Bad Form given");
}

static bool	isGoodForm(const std::string formName, const std::string formTest)
{
	if (formName == formTest)
		return true;
	return false;
}
