/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauker <jkauker@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:18:33 by lbohm             #+#    #+#             */
/*   Updated: 2024/07/05 13:12:10 by jkauker          ###   ########.fr       */
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
