/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:42:31 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 22:36:40 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShruberryCreationForm.hpp"

ShruberryCreationForm::ShruberryCreationForm(void): AForm("ShruberryCreationForm", 145, 137), _target("target")
{
	std::cout << "ShruberryCreationForm constructor" << std::endl;
	return ;
}
ShruberryCreationForm::ShruberryCreationForm(const std::string target): AForm("ShruberryCreationForm", 145, 137), _target(target)
{
	std::cout << "ShruberryCreationForm values constructor" << std::endl;
	return ;
}

ShruberryCreationForm::ShruberryCreationForm(const ShruberryCreationForm& obj): AForm("ShruberryCreationForm", 145, 137)
{
	std::cout << "ShruberryCreationForm copy constructor" << std::endl;
	*this = obj;
	return ;
}

ShruberryCreationForm&	ShruberryCreationForm::operator=(const ShruberryCreationForm& obj)
{
	if (this != &obj)
		this->_target = obj._target;
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm(void)
{
	std::cout << "ShruberryCreationForm destructor" << std::endl;
	return ;
}

void	ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream		file;
	
	checkForExec(executor);
	file.open((this->_target + "_shruberry").c_str());
	if (file.good() == false)
		throw AForm::fileErrorException();
	std::cout << this->_target << "_shruberry" << " has been created" << std::endl;
	file << "           ^           " << std::endl;
	file << "          ^^^          " << std::endl;
	file << "         ^^^^^         " << std::endl;
	file << "        ^^^^^^^        " << std::endl;
	file << "       ^^^^^^^^^       " << std::endl;
	file << "      ^^^^^^^^^^^      " << std::endl;
	file << "     ^^^^^^^^^^^^^     " << std::endl;
	file << "    ^^^^^^^^^^^^^^^    " << std::endl;
	file << "   ^^^^^^^^^^^^^^^^^   " << std::endl;
	file << "  ^^^^^^^^^^^^^^^^^^^  " << std::endl;
	file << " ^^^^^^^^^^^^^^^^^^^^^ " << std::endl;
	file << "^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	file << "          |||          " << std::endl;
	return ;
}
