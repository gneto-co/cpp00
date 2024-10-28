/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:45:23 by gneto-co          #+#    #+#             */
/*   Updated: 2024/07/20 17:10:16 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

    #include "../includes/Contact.hpp"

    std::string Contact::_fields_name[5] = {"First Name", "Last Name", "Nickname",
        "Phone Number", "Darkest Secret"};

    Contact::Contact()
    {
        /* initialize _informations whit a void string */
        for (int i = FirstName; i <= DarkestSecret; i++)
            this->_informations[i] = std::string();
        return ;
    }

    Contact::~Contact()
    {
    }

    bool Contact::set_contact()
    {
        /* loop for each element of _fields_name */
        for (int i = FirstName; i <= DarkestSecret; i++)
        {
            std::cout << "Please enter the " << Contact::_fields_name[i] << ":\n+";
            /* loop while input is NOT VALID */
            while (!(std::getline(std::cin, this->_informations[i]))
                || this->_informations[i].length() == 0)
            {
                if (std::cin.eof() == true)
                {
                    std::cout << EOF_MESSAGE << std::endl;
                    std::exit(0);
                }
                else if (this->_informations[i].length() == 0)
                {
                    this->_informations[i].clear();
                    std::cout << "\033[31mEmpty contact information not allowed.\033[0m" << std::endl;
                    std::cout << "Please enter the " << Contact::_fields_name[i] << ":\n+";
                }
            }
        }
        std::cout << "\033[32mContact added successfully.\033[0m" << std::endl;
        return (true);
    }

    void Contact::get_contact(int index) const
    {
        /* print Contact information in table format */
        std::cout << "|" << std::setw(10) << index;
        for (int i = FirstName; i <= NickName; i++)
        {
            std::cout << "|";
            if (this->_informations[i].length() > 10)
                std::cout << this->_informations[i].substr(0, 9) << ".";
            else
                std::cout << std::setw(10) << this->_informations[i];
        }
        std::cout << "|" << std::endl;
    }