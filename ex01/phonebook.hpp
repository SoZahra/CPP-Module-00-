/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:29 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/15 17:26:36 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_CONTACT
# define MAX_CONTACT 8
#endif

#include "contact.hpp"
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

class PhoneBook
{
  private:
	Contact tab_contact[MAX_CONTACT];
	std::string truncate(std::string str);
	int nb_contact;

  public:
	void ADD();
	void SEARCH();
	PhoneBook();
};

PhoneBook::PhoneBook()
{
	this->nb_contact = 0;
}

std::string PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

bool	isNumber(std::string info)
{
	if (info.length() != 10)
		return (false);
	for (size_t i = 0; i < info.length(); i++)
	{
		if (!isdigit(info[i]))
			return (false);
	}
	return (true);
}

bool	isprintable(const std::string &str)
{
	if (str.find("^[[") != std::string::npos)
		return (false);
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isprint(str[i]) || str[i] == 27)
			return (false);
	}
	return (true);
}

void PhoneBook::ADD()
{
	int	index;

	std::string firstName, lastName, number, nikename, secret;
	index = this->nb_contact;
	if (this->nb_contact >= 8)
		index = this->nb_contact % 8;
	else
		this->nb_contact++;
	std::cout << "Enter your first name: ";
	std::getline(std::cin, firstName);
	if (!std::cin)
	{
		std::cout << "\nExiting program\n";
		exit(0);
	}
	if (firstName.empty() || !isprintable(firstName))
	{
		std::cout << "Failed - cannot be empty and have to be printable\n";
		return ;
	}
	std::cout << "Enter your last name: ";
	std::getline(std::cin, lastName);
	if (!std::cin)
	{
		std::cout << "\nExiting program\n";
		exit(0);
	}
	if (lastName.empty() || !isprintable(lastName))
	{
		std::cout << "Failed - cannot be empty and have to be printable\n";
		return ;
	}
	std::cout << "Enter your number: ";
	std::getline(std::cin, number);
	if (!std::cin)
	{
		std::cout << "\nExiting program\n";
		exit(0);
	}
	if (number.empty() || !isNumber(number) || !isprintable(number))
	{
		std::cout << "Number must contain only digits and have to be 10 number\n";
		return ;
	}
	std::cout << "Enter your nikename: ";
	std::getline(std::cin, nikename);
	if (!std::cin)
	{
		std::cout << "\nExiting program\n";
		exit(0);
	}
	if (nikename.empty() || !isprintable(nikename))
	{
		std::cout << "Failed cannot be empty and have to be printable\n";
		return ;
	}
	std::cout << "Enter your secret: ";
	std::getline(std::cin, secret);
	if (!std::cin)
	{
		std::cout << "\nExiting program\n";
		exit(0);
	}
	if (secret.empty() || !isprintable(secret))
	{
		std::cout << "Failed cannot be empty and have to be printable\n";
		return ;
	}
	tab_contact[index].set_firstN(firstName);
	tab_contact[index].set_lastN(lastName);
	tab_contact[index].set_num(number);
	tab_contact[index].set_nikename(nikename);
	tab_contact[index].set_secret(secret);
}

void PhoneBook::SEARCH()
{
	std::cout << std::setw(10) << "Index"
				<< " | " << std::setw(10) << "First"
				<< " | " << std::setw(10) << "Last"
				<< " | " << std::setw(10) << "Nickname"
				<< " | " << std::endl;

	if (this->nb_contact == 0)
	{
		std::cout << "Phonebook is empty !" << std::endl;
		return ;
	}
	for (int i = 0; i < this->nb_contact; i++)
	{
		std::cout << std::setw(10) << i << " | "
						<< std::setw(10) << truncate(tab_contact[i].get_firstN()) << " | "
						<< std::setw(10) << truncate(tab_contact[i].get_lastN()) << " | "
						<< std::setw(10) << truncate(tab_contact[i].get_nikename()) << " | "
						<< std::endl;
	}
	std::string index;
	std::cout << "Enter index to find a contact:";
	std::getline(std::cin, index);

	if (!std::cin)
	{
		std::cout << "\nExiting program\n";
		exit(0);
	}
	if (index.empty() || !isprintable(index))
	{
		std::cout << "Index cannot be empty and have to be printable\n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	if (!isNumber(index))
	{
		std::cout << "Error index not good format or have nothing to see\n";
		return ;
	}
	try
	{
		int idx = std::atoi(index.c_str());
		if (idx >= 0 && idx < nb_contact)
		{
			std::cout << "First name: " << tab_contact[idx].get_firstN() << std::endl;
			std::cout << "Last name: " << tab_contact[idx].get_lastN() << std::endl;
			std::cout << "Nikename : " << tab_contact[idx].get_nikename() << std::endl;
			std::cout << "Number : " << tab_contact[idx].get_num() << std::endl;
			std::cout << "Dark secret : " << tab_contact[idx].get_secret() << std::endl;
		}
		else
		{
			std::cout << "Index out of range\n";
		}
	}
	catch (...)
	{
		std::cout << "Invalid index\n";
	}
}