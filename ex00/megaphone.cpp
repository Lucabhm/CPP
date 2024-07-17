/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbohm <lbohm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 10:27:08 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/17 10:27:12 by lbohm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cctype>

int	main(int argc, char **argv)
{
	char	c;
	if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; j < std::strlen(argv[i]); j++)
			{
				c = std::toupper(argv[i][j]);
				std::cout << c;
			}
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
