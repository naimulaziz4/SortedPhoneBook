#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H
#include "ContactInfo.h"

struct NodeType{
    ContactInfo info;
    NodeType* next;
};

class SortedType
{
    private:
        NodeType* listData;
        NodeType* cursor;
        int length;

    public:
        SortedType();
        ~SortedType();
        int GetLength();
        ContactInfo GetItem(ContactInfo, bool&);
        void InsertItem(ContactInfo);
        void MakeEmpty();
        bool IsFull();
        void DeleteItem(ContactInfo);
        void ResetList();
        ContactInfo GetNextItem();
};
#endif // SORTEDTYPE_H
