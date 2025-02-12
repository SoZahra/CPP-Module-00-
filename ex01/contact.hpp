/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzayani <fzayani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:52:03 by fzayani           #+#    #+#             */
/*   Updated: 2025/02/12 18:24:18 by fzayani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CONTACT_HPP
#define CONTACT_HPP

# ifndef MAX_CONTACT
 # define MAX_CONTACT 8
# endif

class Contact
{
	public:
		Contact();
		void set_num(std::string num);
		std::string get_num() const;

		void set_secret(std::string secret);
		std::string get_secret() const;

		void set_firstN(std::string firstN);
		std::string get_firstN() const;

		void set_lastN(std::string lastN);
		std::string get_lastN() const;

		void set_nikename(std::string nikename);
		std::string get_nikename() const;

	private:

		std::string num;
		std::string secret;
		std::string firstN;
		std::string lastN;
		std::string nikename;
};

Contact::Contact()
{
}

void Contact::set_num(std::string num)
{
	this->num = num;
}

std::string Contact::get_num() const
{
	return this->num;
}

void Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

std::string Contact::get_secret() const
{
	return this->secret;
}

void Contact::set_firstN(std::string firstN)
{
	this->firstN = firstN;
}

std::string Contact::get_firstN() const
{
	return this->firstN;
}

void Contact::set_lastN(std::string lastN)
{
	this->lastN = lastN;
}

std::string Contact::get_lastN() const
{
	return this->lastN;
}

void Contact::set_nikename(std::string nikename)
{
	this->nikename = nikename;
}

std::string Contact::get_nikename() const
{
	return this->nikename;
}

# endif