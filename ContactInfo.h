#ifndef CONTACTINFO_H
#define CONTACTINFO_H
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

enum RelationType{LESS, EQUAL, GREATER};

class ContactInfo
{
    private:
        string number;
        string name;

    public:
        ContactInfo();
        RelationType ComparedTo(ContactInfo);
        void Initialize(string, string);
        void Print(ofstream&);
        string getNumber();
        string getName();
};
#endif // CONTACTINFO_H
