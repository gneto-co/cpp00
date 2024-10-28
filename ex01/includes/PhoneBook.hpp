/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:47:15 by gneto-co          #+#    #+#             */
/*   Updated: 2024/07/20 16:50:32 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <cstdlib>
# include <iomanip>
# include <string>

class PhoneBook
{
  private:
	Contact _contacts[8];
	int _index;
	bool _full;

  public:
	PhoneBook(void);
	~PhoneBook(void);

	void set_information(void);
	void get_information(void) const;
	void show_instruction(void);
};

#endif