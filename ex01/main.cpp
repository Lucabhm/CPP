/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:16:29 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/03 17:00:31 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	std::string	input;
	Contact		person;
	PhoneBook	list;
	int			i = 0, size = 0;

	while (1)
	{
		input = print_menu();
		if (input == "ADD")
		{
			person = add_person();
			list.people[i] = person;
			i++;
			if (size < 8)
				size++;
			if (i == 8)
				i = 0;
		}
		else if (input == "SEARCH")
			search_person(list, size);
		else if (input == "EXIT")
		{
			std::cout << "EXIT Phonebook" << std::endl;
			return (0);
		}
	}
}

std::string	print_menu(void)
{
	std::string	input;

	std::cout << BANNER << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "[0] ADD" << std::endl;
	std::cout << "[1] SEARCH" << std::endl;
	std::cout << "[2] EXIT" << std::endl;
	std::getline(std::cin, input);
	return (input);
}

Contact	add_person(void)
{
	std::string	input;
	Contact		person;
	std::string	msgs[5] = {"Enter the first Name: ", "Enter the last Name: ", "Enter the Nickname: ", "Enter the Phonenumber: ", "Enter the darkest secret: "};

	std::cout << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << msgs[i];
		std::cin >> input;
		if (i == 0)
			person.first_name = input;
		else if (i == 1)
			person.last_name = input;
		else if (i == 2)
			person.nickname = input;
		else if (i == 3)
			person.phone_number = input;
		else if (i == 4)
			person.darkest_secret = input;
	}
	std::cout << std::endl;
	return (person);
}

void	search_person(PhoneBook list, int size)
{
	int	i, input;

	i = 0;
	print_value("Index");
	std::cout << "|";
	print_value("Firstname");
	std::cout << "|";
	print_value("Lastname");
	std::cout << "|";
	print_value("Nickname");
	std::cout << std::endl;
	for (i = 0; i < size; i++)
		print_person(list.people[i], i);
	std::cout << "Enter the index of the Contact: ";
	std::cin >> input;
	if (input < size)
		print_full_contact(list.people[input]);
	else
		std::cerr << "index is out of range" << std::endl;
}

void	print_person(Contact person, int i)
{
	std::cout << std::right << std::setfill(' ') << std::setw(10) << i << "|";
	print_value(person.first_name);
	std::cout << "|";
	print_value(person.last_name);
	std::cout << "|";
	print_value(person.nickname);
	std::cout << std::endl;
}

void	print_full_contact(Contact person)
{
	std::cout << std::endl;
	std::cout << "First Name: " << person.first_name << std::endl;
	std::cout << "Last Name: " << person.last_name << std::endl;
	std::cout << "Nickname: " << person.nickname << std::endl;
	std::cout << "Phonenumber: " << person.phone_number << std::endl;
	std::cout << "Darkest Secret: " << person.darkest_secret << std::endl;
	std::cout << std::endl;
}

void	print_value(std::string value)
{
	if (value.length() > 10)
		std::cout << value.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setfill(' ') << std::setw(10) << value;
}
