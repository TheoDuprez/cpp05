/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:36:09 by tduprez           #+#    #+#             */
/*   Updated: 2023/11/22 16:19:16 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45), _target("target")
{
	std::cout << "RobotomyRequestForm constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm values constructor" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = obj;
	return ;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
		this->_target = obj._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
	return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::srand(std::time(NULL));
	checkForExec(executor);
	if (static_cast<double>(std::rand()) / RAND_MAX < 0.5)
		throw AForm::failRobotomyException();
	std::cout << "Brrrr... Brrrrr.... Brrrrrrrrrr....." << std::endl;
	std::cout << this->_target << " has been robotomized" << std::endl;
	return ;
}
