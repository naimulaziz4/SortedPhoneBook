#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "SortedType.h"

class PhoneBook
{
    private:
        SortedType ContactList;
        int number_of_contacts;

    public:
        PhoneBook();
        void AddContact(ContactInfo);
        ContactInfo DeleteContact(string);
        void SearchContact(string, ofstream&);
        void PrintPhoneBook(ofstream&);
        void Clear();
        bool SearchContact(string);
        int NumberOfContacts();
};
#endif // PHONEBOOK_H
