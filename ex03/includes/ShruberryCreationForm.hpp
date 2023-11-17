/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:43:09 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/14 22:36:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "./AForm.hpp"

class ShruberryCreationForm : public AForm
{
	private:
		std::string	_target;
		
	public:
		ShruberryCreationForm(void);
		ShruberryCreationForm(const std::string target);
		ShruberryCreationForm(const ShruberryCreationForm& obj);
		ShruberryCreationForm&	operator=(const ShruberryCreationForm& obj);
		~ShruberryCreationForm(void);

		void	execute(Bureaucrat const & executor) const;
};

#endif