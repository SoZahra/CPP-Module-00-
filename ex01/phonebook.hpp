/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:29 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/13 12:10:44 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAX_CONTACT
 # define MAX_CONTACT 8
# endif

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include "contact.hpp"
#include <cctype>
class PhoneBook
{
private :

	Contact tab_contact[MAX_CONTACT];
	std::string truncate(std::string str);
	int nb_contact;

public :
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
	if(str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

bool isNumber(std::string info)
{
	for (size_t i = 0; i < info.length(); i++)
	{
		if(!isdigit(info[i]))
			return false;
	}
	return true;
}

void PhoneBook::ADD()
{
	std::string info;

	int index = this->nb_contact;

	if(this->nb_contact >= 8)
		index = this->nb_contact % 8;
	else
		this->nb_contact++;

	std::cout << "Enter your first name: ";
	if(!(std::cin >> info) || info.empty())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Failed cannot be empty\n";
		return ;
	}
	tab_contact[index].set_firstN(info);

	std::cout << "Enter your last name: ";
	std::cin >> info;
	if(info.empty())
	{
		std::cout << "Failed cannot be empty\n";
		return ;
	}
	tab_contact[nb_contact].set_lastN(info);

	std::cout << "Enter your number: ";
	std::cin >> info;
	if(info.empty() || !isNumber(info))
	{
		std::cout << "Number must contain only digits\n";
		return ;
	}
	tab_contact[nb_contact].set_num(info);

	std::cout << "Enter your nikename: ";
	std::cin >> info;
	if(info.empty())
	{
		std::cout << "Failed cannot be empty\n";
		return ;
	}
	tab_contact[nb_contact].set_nikename(info);

	std::cout << "Enter your secret: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, info);
	if(info.empty())
	{
		std::cout << "Failed cannot be empty\n";
		return ;
	}
	tab_contact[nb_contact].set_secret(info);
	this->nb_contact++;
}

void PhoneBook::SEARCH()
{
	if(this->nb_contact == 0)
	{
		std::cout << "Phonebook is empty !" << std::endl;
		return ;
	}
	for (int i = 0; i < this->nb_contact; i++)
	{
		std::cout 	<< std::setw(10) << i << " | "
					<< std::setw(10) << truncate(tab_contact[i].get_firstN()) << " | "
					<< std::setw(10) << truncate(tab_contact[i].get_lastN()) << " | "
					<< std::setw(10) << truncate(tab_contact[i].get_nikename()) << " | " << std::endl;
	}
	std::string index;
	std::cout << "Enter index to find a contact:";
	std::cin >> index;

	try
	{
		int idx = std::atoi(index.c_str());
		if(idx >= 0 && idx < nb_contact)
		{
			std::cout << "First name: " << tab_contact[idx].get_firstN() << std::endl;
			std::cout << "Last name: " << tab_contact[idx].get_lastN() << std::endl;
			std::cout << "Nikename : " << tab_contact[idx].get_nikename() << std::endl;
			std::cout << "Number : " << tab_contact[idx].get_num() << std::endl;
			std::cout << "Dark secret : " << tab_contact[idx].get_secret()<< std::endl;
		}
		else{
			std::cout << "Index out of range\n";
		}
	}
	catch (...){
		std::cout << "Invalid index\n";
	}
}