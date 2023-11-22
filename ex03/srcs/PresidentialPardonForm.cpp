/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:35:43 by tduprez           #+#    #+#             */
/*   Updated: 2023/11/22 17:10:57 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm", 25, 5), _target("target")
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
	return ;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm values constructor" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm("PresidentialPardonForm", 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = obj;
	return ;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
		this->_target = obj._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkForExec(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return ;
}
