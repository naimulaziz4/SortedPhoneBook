#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP
#include "SortedType.h"

SortedType::SortedType()
{
    listData=NULL;
    cursor=NULL;
    length=0;
}
SortedType::~SortedType()
{
    NodeType* tempPointer;

    while(listData!=NULL)
    {
        tempPointer=listData;
        listData=listData->next;
        delete tempPointer;
    }
}
int SortedType::GetLength()
{
    return length;
}
ContactInfo SortedType::GetItem(ContactInfo otherContact, bool& found)
{
    NodeType* location=listData;
    bool moreToSearch=(location!=NULL); found=false;

    while(moreToSearch && !found)
    {
        switch(otherContact.ComparedTo(location->info))
        {
            case LESS:
            case GREATER:
                location=location->next;
                moreToSearch=(location!=NULL);
                break;

            case EQUAL:
                found=true;
                otherContact=location->info;
        }
    }
    return otherContact;
}
void SortedType::DeleteItem(ContactInfo otherContact)
{
    NodeType* location=listData; NodeType* tempLocation;

    if(otherContact.ComparedTo(listData->info)==EQUAL)
    {
        tempLocation=location;
        listData=listData->next;
    }
    else
    {
        while(otherContact.ComparedTo((location->next)->info)!=EQUAL)
            location=location->next;

        tempLocation=location->next;
        location->next=(location->next)->next;
    }
    delete tempLocation;
    length--;
}
void SortedType::InsertItem(ContactInfo otherContact)
{
    NodeType* location=new NodeType;
    location->info=otherContact;
    location->next=listData;

    listData=location;
    length++;
}
void SortedType::MakeEmpty()
{
    NodeType* tempPointer=listData;

    while(listData!=NULL)
    {
        tempPointer=listData;
        listData=listData->next;
        delete tempPointer;
    }
    length=0;
}
bool SortedType::IsFull()
{
    NodeType* location;

    try{
        location=new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}
void SortedType::ResetList()
{
    cursor=NULL;
}
ContactInfo SortedType::GetNextItem()
{
    if(cursor==NULL)
        cursor=listData;
    else
        cursor=cursor->next;

    return cursor->info;
}
#endif // SORTEDTYPE_CPP
