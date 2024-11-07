/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:45:23 by gneto-co          #+#    #+#             */
/*   Updated: 2024/11/07 11:07:44 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(void)
{
    return;
}

Contact::~Contact(void)
{
    return;
}

static std::string prompt_loop(std::string message)
{
    std::string str;

    while (1)
    {
        std::cout << message << PROMPT;
        std::getline(std::cin, str);
        std::cout << std::endl;
        if (std::cin.eof() == true)
        {
            std::cout << EOF_MESSAGE << std::endl;
            exit(1);
        }
        if (str.length() > 0)
            break;
        MOVE_CURSOR_UP(3);
    }
    MOVE_CURSOR_UP(3) << CURSOR_ALL_LEFT << CLEAR_SCREEN_FORWARD_CURSOR;
    return str;
}

void Contact::new_contact()
{
    this->first_name = prompt_loop("First name: ");
    this->last_name = prompt_loop("Last name: ");
    this->nickname = prompt_loop("Nickname: ");
    this->phone_number = prompt_loop("Phone number: ");
    this->darkest_secret = prompt_loop("Darkest Secret: ");
}

std::string letter_round_10(std::string str)
{
    if (str.length() > 10)
        str = str.substr(0, 9) + ".";
    else
    {
        int spaces = 10 - str.length();
        for (int i = 0; i < spaces; i++)
            str = ' ' + str;
    }
    return str;
}

void Contact::print_contact_1(int index) const
{
    std::cout << "│" << std::setw(10) << index;
    std::cout << "│" << letter_round_10(this->first_name);
    std::cout << "│" << letter_round_10(this->last_name);
    std::cout << "│" << letter_round_10(this->nickname);
    std::cout << "│" << std::endl;
}
void Contact::print_contact_2(int i) const
{
    std::cout << GREEN "Contact number\t\t" RESET << i << std::endl;
    std::cout << GREEN "First name\t\t" RESET << this->first_name << std::endl;
    std::cout << GREEN "Last name\t\t" RESET << this->last_name << std::endl;
    std::cout << GREEN "Nickname\t\t" RESET << this->nickname << std::endl;
    std::cout << GREEN "Phone number\t\t" RESET << this->phone_number << std::endl;
    std::cout << GREEN "Darkest Secret\t\t" RESET << this->darkest_secret << std::endl;
    std::cin.get();
    MOVE_CURSOR_UP(7) << CURSOR_ALL_LEFT << CLEAR_SCREEN_FORWARD_CURSOR;
}
