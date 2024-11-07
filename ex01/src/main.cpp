/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:28:03 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/07 11:02:46 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

int main(void)
{
	PhoneBook PhoneBook;
	std::string command;
	int i = 0;

	while (1)
	{
		std::cout << GREEN "[" << i << "]" RESET << std::endl;
		std::cout << MAIN_MESSAGE << PROMPT << CYAN;
		std::getline(std::cin, command);
		std::cout << RESET << std::endl;
		MOVE_CURSOR_UP(7);
		if (std::cin.eof() == true)
		{
			std::cout << EOF_MESSAGE << std::endl;
			exit(1);
		}
		else if (command == ADD)
		{
			std::cout << CLEAR_SCREEN_FORWARD_CURSOR;
			PhoneBook.add();
		}
		else if (command == SEARCH)
		{
			std::cout << CLEAR_SCREEN_FORWARD_CURSOR;
			PhoneBook.search();
		}
		else if (command == EXIT)
		{
			std::cout << EXIT_MESSAGE << std::endl;
			break;
		}
		i++;
	}
	return (0);
}
