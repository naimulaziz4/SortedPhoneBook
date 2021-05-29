#ifndef CONTACTINFO_CPP
#define CONTACTINFO_CPP
#include "ContactInfo.h"

ContactInfo::ContactInfo()
{
    name="";
    number="";
}
void ContactInfo::Initialize(string newName, string newNumber)
{
    name=newName;
    number=newNumber;
}
RelationType ContactInfo::ComparedTo(ContactInfo otherContact)
{
    if(number>otherContact.number)
        return GREATER;
    else if(number<otherContact.number)
        return LESS;

    return EQUAL;
}
void ContactInfo::Print(ofstream& out)
{
    out << name << "\t" << number << endl;
}
string ContactInfo::getName()
{
    return name;
}
string ContactInfo::getNumber()
{
    return number;
}

#endif // CONTACTINFO_CPP
