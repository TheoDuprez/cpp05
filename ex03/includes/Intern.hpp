/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:45:07 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/15 00:03:35 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./ShruberryCreationForm.hpp"

class Intern
{
	private:
		
	public:
		Intern(void);
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);
		~Intern(void);

		AForm*	makeForm(const std::string formName, const std::string target) const;

		class BadFormException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif