/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:29 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/04 19:29:45 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contact.hpp"

# ifndef MAX_CONTACT
 # define MAX_CONTACT 8
# endif

class PhoneBook
{
private :

	Contact tab_contact[MAX_CONTACT];
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

void PhoneBook::ADD()
{
	std::string info;

	std::cout << "Enter your first name: ";
	std::cin >> info;
	if(info.empty())
		std::cout << "Failed cannot be empty\n"; return ;
	tab_contact[nb_contact].set_firstN(info);

	std::cout << "Enter your last name: ";
	std::cin >> info;
	if(info.empty())
		std::cout << "Failed cannot be empty\n"; return ;
	tab_contact[nb_contact].set_lastN(info);

	std::cout << "Enter your number: ";
	std::cin >> info;
	if(info.empty())
		std::cout << "Failed cannot be empty\n"; return ;
	tab_contact[nb_contact].set_num(info);

	std::cout << "Enter your nikename: ";
	std::cin >> info;
	if(info.empty())
		std::cout << "Failed cannot be empty\n"; return ;
	tab_contact[nb_contact].set_nikename(info);

	std::cout << "Enter your secret: ";
	std::cin >> info;
	if(info.empty())
		std::cout << "Failed cannot be empty\n"; return ;
	tab_contact[nb_contact].set_secret(info);
}

void PhoneBook::SEARCH()
{

}