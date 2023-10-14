/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:43:09 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 22:35:24 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
		
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm(void);

		void	execute(Bureaucrat const & executor) const;
};
