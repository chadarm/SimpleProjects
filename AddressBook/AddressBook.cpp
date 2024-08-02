// AddressBook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "AddressBook.h"



int main()
{
    bool running = true;
    do
    {
        running = UserInteraction();
    } while (running);
    return 0;
}

bool UserInteraction()
{
    ContactsList contactList;
    char choice;

    do
    {
        PromptUser( "\n1. Add Contact");
        PromptUser( "2. Display Contacts");
        PromptUser( "3. Search Contact");
        PromptUser( "4. Delete Contact");
        PromptUser( "5. Exit");
        choice = GetCharInput( "Enter choice: ", "12345");
        

        switch (choice)
        {
        case '1':
            contactList.AddContact();
            break;
        case '2':
            contactList.DisplayContacts();
            break;
        case '3':
            contactList.SearchContact();
            break;
        case '4':
            contactList.DeleteContact();
            break;
        case '5':
            break;
        default:
            PromptUser( "Invalid choice.");
        }
    } while (choice != '5');

    return false;
}

void ContactsList::AddContact()
{
    Contact newContact;
    newContact.name = GetStringInput("Enter name: ");
    newContact.phone = GetStringInput("Enter phone: ");
    newContact.email = GetStringInput("Enter email: ");
    contacts.push_back(newContact);
    PromptUser("Contact added.");
}

void ContactsList::DisplayContacts()
{
    for (const auto& contact : contacts)
    {
        std::cout << "Name: " << contact.name << ", Phone: "
            << contact.phone << ", Email: " << contact.email << std::endl;
    }
}

void ContactsList::SearchContact()
{
    std::string searchTerm = GetStringInput("Enter name to search: ");


    bool found = false;
    for (const auto& contact : contacts)
    {
        if (contact.name == searchTerm)
        {
            std::cout << "Name: " << contact.name << ", Phone: "
                << contact.phone << ", Email: " << contact.email << std::endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        PromptUser( "Contact not found.");
    }
}

void ContactsList::DeleteContact()
{
    std::string nameToDelete = GetStringInput("Enter name of contact to delete: ");

    auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact& contact)
        { return contact.name == nameToDelete; });

    if (it != contacts.end())
    {
        contacts.erase(it, contacts.end());
        PromptUser("Contact deleted.");
    }
    else
    {
        PromptUser("Contact not found.");
    }
}
