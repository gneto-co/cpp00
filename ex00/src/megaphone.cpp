/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:07:41 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/05 10:32:56 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* includes */
#include <cctype>
#include <iostream>

/* main function */
int	main(int ac, char **av)
{
    /* if there is any word */
	if (ac > 1)
	{
		/* repeat for each word */
		for (int i = 1; i < ac; i++)
		{
			/* repeat for each char on the word */
			for (int j = 0; av[i][j] != '\0'; j++)
			{
				av[i][j] = (char)toupper(av[i][j]);
			}
            /* print word */
            std::cout << av[i];
		}
        /* new line */
        std::cout << std::endl;
	}
    /* if there is no words */
	else
	{
        /* default message and new line */
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return (0);
}
