#include "PhoneBook.h"
#include "PhoneBook.cpp"

int main()
{
    cout << "This program tests the PhoneBook class. " << endl;

    PhoneBook myPhoneBook; ContactInfo tempContact; string tempName, tempNumber;
    ifstream inFile; inFile.open("input.txt");
    while(inFile >> tempName)
    {
        inFile >> tempNumber;
        tempContact.Initialize(tempName, tempNumber);
        myPhoneBook.AddContact(tempContact);
    }
    inFile.close();

    ofstream outFile; outFile.open("output.txt");
    myPhoneBook.PrintPhoneBook(outFile);

    if(myPhoneBook.SearchContact("987654"))
    {
        tempContact=myPhoneBook.DeleteContact("987654");
        outFile << tempContact.getName() << " " << tempContact.getNumber() << " was deleted from list. " << endl;
    }
    else
        outFile << "987654 could not be found to be deleted from list. " << endl;

    myPhoneBook.PrintPhoneBook(outFile);

    myPhoneBook.SearchContact("012345", outFile);

    myPhoneBook.PrintPhoneBook(outFile);

    outFile << myPhoneBook.NumberOfContacts() << endl;

    myPhoneBook.Clear();

    outFile << myPhoneBook.NumberOfContacts() << endl;

    outFile.close();

    return 0;
}
