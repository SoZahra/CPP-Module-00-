/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:15 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/12 18:19:32 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int main()
{
	PhoneBook repertoire;
	std::string command;

	while(1)
	{
		std::cout << "Enter command (ADD/SEARCH/EXIT): ";
		if(!(std::cin >> command))
		{
			std::cout << "\nExiting program\n";
			break;
		}

		if(command == "ADD")
			repertoire.ADD();
		else if(command == "SEARCH")
			repertoire.SEARCH();
		else if(command == "EXIT")
			return (0);
	}
	return (0);
}