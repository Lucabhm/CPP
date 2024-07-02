/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:16:29 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/02 15:52:45 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	std::string	input;
	Contact		person;
	PhoneBook	list;
	int			i;

	i = 0;
	while (1)
	{
		input = print_menu();
		if (input == "ADD")
		{
			person = add_person();
			list.people[i] = person;
			i++;
		}
		else if (input == "SEARCH")
			search_person(list);
		else if (input == "EXIT")
		{
			std::cout << "EXIT Phonebook" << std::endl;
			return (0);
		}
	}
}

void	search_person(PhoneBook list)
{
	std::string	input;
	int			i;

	i = 0;
	std::cout << "Enter the first name you are searching for" << std::endl;
	std::cin >> input;
	for (i = 0; i < 8; i++)
	{
		if (list.people[i].first_name == input)
		{
			print_person(list.people[i], i);
			break ;
		}
	}
	if (i == 8)
	{
		for (i = 0; i < 8; i++)
			print_person(list.people[i], i);
	}
}

void	print_person(Contact person, int i)
{
	int	len;

	std::cout << i << "        |";
	len = person.first_name.length();
	if (len > 10)
		std::cout << person.first_name.substr(0, 9) << "." << "|";
	else
		std::cout << person.first_name.append(10 - len, ' ') << "|";
	len = person.last_name.length();
	if (len > 10)
		std::cout << person.last_name.substr(0, 9) << "." << "|";
	else
		std::cout << person.last_name.append(10 - len, ' ') << "|";
	len = person.nickname.length();
	if (len > 10)
		std::cout << person.nickname.substr(0, 9) << "." << std::endl;
	else
		std::cout << person.nickname.append(10 - len, ' ') << std::endl;
}

Contact	add_person(void)
{
	std::string	input;
	int			nbr;
	Contact		person;
	std::string	msgs[5] = {"Enter the first Name", "Enter the last Name", "Enter the Nickname", "Enter the Phonenumber", "Enter the darkest secret"};
	
	for (int i = 0; i < 5; i++)
	{
		std::cout << msgs[i] << std::endl;
		if (i != 3)
			std::cin >> input;
		else
			std::cin >> nbr;
		if (i == 0)
			person.first_name = input;
		else if (i == 1)
			person.last_name = input;
		else if (i == 2)
			person.nickname = input;
		else if (i == 3)
			person.phone_number = nbr;
		else if (i == 4)
			person.darkest_secret = input;
	}
	return (person);
}

std::string	print_menu(void)
{
	std::string	input;

	std::cout << BANNER << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "[0] ADD" << std::endl;
	std::cout << "[1] SEARCH" << std::endl;
	std::cout << "[2] EXIT" << std::endl;
	std::cin >> input;
	return (input);
}