
#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
	this->_max = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::add(void)
{
	if (this->_index > 7)
		this->_index = 0;
	this->_contacts[this->_index].new_contact();
	this->_index++;
	if (this->_max < this->_index)
		this->_max = this->_index;
}

void PhoneBook::search(void) const
{
	int lines_amount = 0;

	/* print full table */
	{
		lines_amount += 2;
		std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
		for (int i = 0; i < this->_max; i++)
		{
			this->_contacts[i].print_contact_1(i + 1);
			if (i + 1 != this->_max)
			{
				std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
				lines_amount++;
			}
			lines_amount++;
		}
		std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
	}
	/* get index */
	int index = 0;
	{
		int error = 0;
		std::string str;
		while (1)
		{
			std::cout << CONTACT_MESSAGE;
			if (error == 0)
				std::cout << std::endl;
			else if (error == 1)
				std::cout << CONTACT_ERROR_MESSAGE << std::endl;
			else if (error == 2)
				std::cout << INVALID_INPUT_MESSAGE << std::endl;
			error = 0;
			std::cout << PROMPT;
			std::getline(std::cin, str);
			if (std::cin.eof() == true)
			{
				std::cout << EOF_MESSAGE << std::endl;
				exit(1);
			}
			if (str.length() == 1 && str.compare("0") >= 0 && str.compare("8") <= 0)
			{
				index = std::atoi(str.c_str());
				if (index <= this->_max)
					break;
				else
					error = 1;
			}
			else
				error = 2;
			MOVE_CURSOR_UP(5) << CURSOR_ALL_LEFT << CLEAR_SCREEN_FORWARD_CURSOR;
		}
		MOVE_CURSOR_UP(5) << CURSOR_ALL_LEFT << CLEAR_SCREEN_FORWARD_CURSOR;
	}
	/* print contact[index] */
	{
		if (index > 0)
			this->_contacts[index - 1].print_contact_2(index);
	}
	/* wait and reset text */
	for (int i = 0; i < lines_amount; i++)
		MOVE_CURSOR_UP(1);
	std::cout << CURSOR_ALL_LEFT << CLEAR_SCREEN_FORWARD_CURSOR;
}