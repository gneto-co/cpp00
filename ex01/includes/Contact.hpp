/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:47:23 by gneto-co          #+#    #+#             */
/*   Updated: 2024/07/20 17:13:28 by gneto-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <string>

# include "Strings.h"

class Contact
{
  private:
	static std::string _fields_name[5];
	std::string _informations[5];

	enum	Field
	{
		FirstName = 0,
		LastName,
		NickName,
		PhoneNumber,
		DarkestSecret
	};

  public:
	Contact(void);
	~Contact(void);

	bool set_contact();
	void get_contact(int index) const;
};

#endif