/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:16:47 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/04 13:15:19 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>

class	Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		std::string	get_first(){return (first_name);}
		std::string	get_last(){return (last_name);}
		std::string	get_nick(){return (nickname);}
		std::string	get_nbr(){return (phone_number);}
		std::string	get_secret(){return (darkest_secret);}
		void		change_value(std::string value, int i)
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
		int			check_input()
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
};

class	PhoneBook
{ 
	public:
		class Contact people[8];
};


std::string	print_menu(void);
Contact		add_person(void);
void		print_person(Contact person, int i);
void		print_full_contact(Contact person);
void		print_value(std::string value);
void		search_person(PhoneBook list, int size);
int			check_digit(char c);
int			check_for_nbr(std::string input);

# define BANNER \
"    +-+-+-+-+-+-+-+-+-+\n" \
"    |P|h|o|n|e|b|o|o|k|\n" \
"    +-+-+-+-+-+-+-+-+-+"

#endif