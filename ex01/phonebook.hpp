/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:16:47 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/02 15:20:43 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cstring>

class	Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		int			phone_number;
		std::string	darkest_secret;
};

class	PhoneBook
{ 
	public:
		class Contact people[8];
};


std::string	print_menu(void);
Contact		add_person(void);
void		print_person(Contact person, int i);
void		search_person(PhoneBook list);

# define BANNER \
"    +-+-+-+-+-+-+-+-+-+\n" \
"    |P|h|o|n|e|b|o|o|k|\n" \
"    +-+-+-+-+-+-+-+-+-+"

#endif