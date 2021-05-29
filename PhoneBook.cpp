#ifndef PHONEBOOK_CPP
#define PHONEBOOK_CPP
#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
    number_of_contacts=0;
}
void PhoneBook::AddContact(ContactInfo otherContact)
{
    ContactList.InsertItem(otherContact);
    number_of_contacts++;
}
ContactInfo PhoneBook::DeleteContact(string newNumber)
{
    //Assures a contact exists with the number sent as argument.
    //Preferred searching of contact existence before deletion from calling function.
    ContactInfo tempContact; tempContact.Initialize("", newNumber);
    bool found=false;
    tempContact=ContactList.GetItem(tempContact, found);

    if(found)
        ContactList.DeleteItem(tempContact);

    number_of_contacts--;
    return tempContact;
}
bool PhoneBook::SearchContact(string newNumber)
{
    ContactInfo tempContact; tempContact.Initialize("", newNumber); bool found=false;
    tempContact=ContactList.GetItem(tempContact, found);

    return found;
}
void PhoneBook::SearchContact(string newNumber, ofstream& out)
{
    ContactInfo tempContact; tempContact.Initialize("", newNumber);
    bool found=false;
    tempContact=ContactList.GetItem(tempContact, found);
    if(found)
        out << tempContact.getName() << " " << tempContact.getNumber() << " was found in the list. " << endl;
    else
        out << "No contact with number " << tempContact.getNumber() << " was found in the list. "  << endl;
}
void PhoneBook::PrintPhoneBook(ofstream& out)
{
    ContactInfo tempContact;
    ContactList.ResetList();
    for(int count=0; count<number_of_contacts; count++)
    {
        tempContact=ContactList.GetNextItem();
        out << tempContact.getName() << "\t" << tempContact.getNumber() << endl;
    }
    ContactList.ResetList();
}
void PhoneBook::Clear()
{
    ContactList.MakeEmpty();
    number_of_contacts=0;
}
int PhoneBook::NumberOfContacts()
{
    return number_of_contacts;
}

#endif // PHONEBOOK_CPP
