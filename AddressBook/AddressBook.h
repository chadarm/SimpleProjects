#pragma once

#include "InputOutput.h"
#include <vector>
#include <algorithm>


bool UserInteraction();


struct Contact
{
	std::string name;
	std::string phone;
	std::string email;
};

class ContactsList
{
public:
	ContactsList() 
	{
		contacts = std::vector<Contact>();
	};
	void AddContact();
	void DisplayContacts();
	void SearchContact();
	void DeleteContact();

private:
	std::vector<Contact> contacts;
};




