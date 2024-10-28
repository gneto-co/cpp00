/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:28:03 by gneto-co          #+#    #+#             */
/*   Updated: 2024/10/11 14:30:49 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"
#include "../includes/PhoneBook.hpp"

int	main(void)
{
	PhoneBook PhoneBook;
	bool run = true;
	std::string command;

	PhoneBook.show_instruction();
	std::cout << PROMPT;
	while (run && std::getline(std::cin, command))
	{
		if (std::cin.eof() == true)
		{
			std::cout << EOF_MESSAGE << std::endl;
			exit(0);
		}
		else if (command.compare("ADD") == 0)
			PhoneBook.set_information();
		else if (command.compare("SEARCH") == 0)
			PhoneBook.get_information();
		else if (command.compare("EXIT") == 0)
		{
			std::cout << EXIT_MESSAGE << std::endl;
			run = false;
			continue ;
		}
		command.clear();
		PhoneBook.show_instruction();
		std::cout << PROMPT;
	}
	if (run)
	{
		std::cout << EOF_MESSAGE << command << std::endl << EXIT_MESSAGE << std::endl;
	}
	return (0);
}