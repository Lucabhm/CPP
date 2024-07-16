/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:17:58 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/16 12:10:15 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

PhoneBook::PhoneBook(){}
PhoneBook::~PhoneBook(){}

std::string	Contact::get_first(void){return (first_name);}
std::string	Contact::get_last(void){return (last_name);}
std::string	Contact::get_nick(void){return (nickname);}
std::string	Contact::get_nbr(void){return (phone_number);}
std::string	Contact::get_secret(void){return (darkest_secret);}

void	Contact::change_value(std::string value, int i)
{
	if (i == 0)
		first_name = value;
	else if (i == 1)
		last_name = value;
	else if (i == 2)
		nickname = value;
	else if (i == 3)
		phone_number = value;
	else if (i == 4)
		darkest_secret = value;
}

int	Contact::check_input()
{
	if (first_name.empty())
		return (1);
	if (last_name.empty())
		return (1);
	if (nickname.empty())
		return (1);
	if (phone_number.empty())
		return (1);
	if (darkest_secret.empty())
		return (1);
	return (0);
}