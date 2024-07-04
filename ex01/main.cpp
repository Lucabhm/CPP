/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:16:29 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/04 13:33:04 by lbohm            ###   ########.fr       */
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
			if (!person.check_input())
			{
				list.people[i] = person;
				i++;
				if (size < 8)
					size++;
				if (i == 8)
					i = 0;
			}
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

	std::cout << BANNER << std::endl << std::endl;
	std::cout << "Options:" << std::endl;
	std::cout << "[0] ADD" << std::endl;
	std::cout << "[1] SEARCH" << std::endl;
	std::cout << "[2] EXIT" << std::endl << std::endl;
	std::cout << "Enter option: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::exit(0);
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
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::exit(0);
		person.change_value(input, i);
	}
	std::cout << std::endl;
	return (person);
}

void	search_person(PhoneBook list, int size)
{
	int			i = 0, nbr = 0;
	std::string	input;

	std::cout << std::endl;
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
	std::getline(std::cin, input);
	if (std::cin.eof())
		std::exit(0);
	if (!input.empty() && check_for_nbr(input))
	{
		try
		{
			nbr = std::stoi(input);
			if (nbr < size)
				print_full_contact(list.people[nbr]);
			else
				std::cerr << "Index is out of range" << std::endl;
		}
		catch (std::out_of_range)
		{
			std::cerr << "Nbr is not in range" << std::endl;
		}
	}
	else
		std::cerr << "Invalide input" << std::endl;
}

void	print_person(Contact person, int i)
{
	std::cout << std::right << std::setfill(' ') << std::setw(10) << i << "|";
	print_value(person.get_first());
	std::cout << "|";
	print_value(person.get_last());
	std::cout << "|";
	print_value(person.get_nick());
	std::cout << std::endl;
}

void	print_full_contact(Contact person)
{
	std::cout << std::endl;
	std::cout << "First Name: " << person.get_first() << std::endl;
	std::cout << "Last Name: " << person.get_last() << std::endl;
	std::cout << "Nickname: " << person.get_nick() << std::endl;
	std::cout << "Phonenumber: " << person.get_nbr() << std::endl;
	std::cout << "Darkest Secret: " << person.get_secret() << std::endl;
	std::cout << std::endl;
}

void	print_value(std::string value)
{
	if (value.length() > 10)
		std::cout << value.substr(0, 9) << ".";
	else
		std::cout << std::right << std::setfill(' ') << std::setw(10) << value;
}

int	check_digit(char c)
{
	return (std::isdigit(c));
}

int	check_for_nbr(std::string input)
{
	return (std::all_of(input.begin(), input.end(), check_digit));
}
