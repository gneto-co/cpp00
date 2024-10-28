
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_full = false;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::set_information(void)
{
	std::string input;
	/* if phonebook is NOT full */
	if (this->_full == false)
	{
		/* print contact index */
		std::cout << "This is your contact #" << this->_index + 1 << std::endl;
		/* if set_contact worked */
		if (this->_contacts[this->_index].set_contact() == true)
		{
			/* if _index on max, _full == true */
			/* else _index++ */
			if (this->_index == 7)
				this->_full = true;
			else
				this->_index++;
		}
	}
	/* if phonebook is FULL */
	else
	{
		/* print message and get user in */
		std::cout << "Your phonebook is full." << std::endl;
		std::cout << "Do you want to delete your #1 contact?" << std::endl;
		std::cout << "1 - Yes" << std::endl;
		std::cout << "0 - No" << std::endl;
		getline(std::cin, input);
		/* if eof, exit */
		if (std::cin.eof() == true)
		{
			std::cout << EOF_MESSAGE << std::endl;
			std::exit(0);
		}
		/* if input == 1 (yes), move up all contacts, add new contact */
		else if (input.compare("1") == 0)
		{
			for (int i = 1; i < 8; i++)
				this->_contacts[i - 1] = this->_contacts[i];
			std::cout << "This is your contact #8" << std::endl;
			this->_contacts[this->_index].set_contact();
		}
		/* if input != 1 (no) back to main menu */
		else
			std::cout << "Back to main menu..." << std::endl;
	}
}

void PhoneBook::get_information() const
{
	int index;

	/* if theres is no contact print a message */
	if (this->_index == 0)
		std::cout << "\033[31mPlease add at least one contact before searching.\033[0m" << std::endl;
	/* id there is at least 1 contact */
	else
	{
		std::string input;
		std::cout << GET_INFO_PROMPT;
		/*
			* while
			*  invalid read
			*  input > 1 char
			*  input is not a char between 0 and 8
			*  is not a existent index
			*/
		while (1)
		{
			std::getline(std::cin, input);
			/* EOF */
			if (std::cin.eof() == true)
			{
				std::cout << EOF_MESSAGE << std::endl;
				std::exit(0);
			}
			/* not a single char between '0' and '8' */
			else if (input.length() > 1 || input.compare("0") < 0
				|| input.compare("8") > 0)
			{
				std::cin.clear();
				std::cout << "\033[31mPlease give a number between 1 and 8\033[0m\n";
				std::cout << GET_INFO_PROMPT;
			}
			/* not a existent index */
			else if (std::atoi(input.c_str()) - 1 >= this->_index
				&& this->_full == false)
			{
				std::cout << "\033[33mYou only have " << this->_index << " Contacts saved.\033[0m" << std::endl;
				std::cin.clear();
				std::cout << GET_INFO_PROMPT;
			}
            /* print Contact[index] data */
			else
			{
				index = std::atoi(input.c_str());
				if (index > 0)
				{
					std::cout << "|-------------------------------------------|" << std::endl;
					std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
					std::cout << "|----------|----------|----------|----------|" << std::endl;
					this->_contacts[index - 1].get_contact(index);
					std::cout << "|-------------------------------------------|" << std::endl;
				}
				else
					std::cout << "Exiting search mode now." << std::endl;
				break ;
			}
		}
	}
}

void PhoneBook::show_instruction(void)
{
	std::cout << "\033[KEnter your command [ADD, SEARCH, EXIT]:" << std::endl;
}