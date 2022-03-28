#include "linkedlist.h"

LinkedList::LinkedList()
    : head(nullptr)
{
    cout << "Creating list" << endl;
}

LinkedList::~LinkedList()
{
    cout << "Destroying list" << endl;
    Empty();
}

void LinkedList::Add(int v)
{
    Node* n = new Node();
    n->data = v;
    n->next = this->head;
    head = n;
}

void LinkedList::Empty()
{
    Node* p = head;
    while (nullptr != p)
    {
        p = p->next;
        delete head;
        head = p;
    }
}

bool LinkedList::IsEmpty()
{
    return nullptr == head;
}

bool LinkedList::Find(int v)
{
    bool found = false;
    Node* p = head;
    while (nullptr != p)
    {
        if (p->data == v)
        {
            found = true;
            break;
        }
        p = p->next;
    }
    return found;
}

//void LinkedList::Remove(int v)
//{
//    if (!IsEmpty())
//    {
//        Node* b = nullptr;
//        Node* p = head;
//        while(nullptr != p)
//        {
//            if (v != p->data)
//            {
//                b = p;
//                p = p->next;
//            }
//            else
//            {
//                if (nullptr != b)
//                {
//                    b->next = p->next;
//                }
//                else
//                {
//                    head = p->next;
//                }
//                p->next = nullptr;
//                delete p;
//                p = nullptr;
//            }
//        }
//    }
//}

//void LinkedList::RemoveAll(int v)
//{
//    if (!IsEmpty())
//    {
//        Node* b = nullptr;
//        Node* p = head;
//        while(nullptr != p)
//        {
//            if (v != p->data)
//            {
//                b = p;
//                p = p->next;
//            }
//            else
//            {
//                if (nullptr != b)
//                {
//                    b->next = p->next;
//                    p->next = nullptr;
//                    delete p;
//                    p = b->next;
//                }
//                else
//                {
//                    head = p->next;
//                    p->next = nullptr;
//                    delete p;
//                    p = head;
//                }
//            }
//        }
//    }
//}

void LinkedList::Remove(int v, bool (*criteria)(int a, int b))
{
    if (/*(nullptr != criteria) && */!IsEmpty())
    {
        Node* b = nullptr;
        Node* p = head;
        if (nullptr == criteria)
        {
            criteria = &Equal;
        }
        while(nullptr != p)
        {
            if (true != criteria(p->data, v))
            {
                b = p;
                p = p->next;
            }
            else
            {
                if (nullptr != b)
                {
                    b->next = p->next;
                }
                else
                {
                    head = p->next;
                }
                p->next = nullptr;
                delete p;
                p = nullptr;
            }
        }
    }
}

void LinkedList::RemoveAll(int v, bool (*criteria)(int a, int b))
{
    if (/*(nullptr != criteria) && */!IsEmpty())
    {
        Node* b = nullptr;
        Node* p = head;
        if (nullptr == criteria)
        {
            criteria = &Equal;
        }
        while(nullptr != p)
        {
            if (true != criteria(p->data, v))
            {
                b = p;
                p = p->next;
            }
            else
            {
                if (nullptr != b)
                {
                    b->next = p->next;
                    p->next = nullptr;
                    delete p;
                    p = b->next;
                }
                else
                {
                    head = p->next;
                    p->next = nullptr;
                    delete p;
                    p = head;
                }
            }
        }
    }
}

bool LinkedList::Equal(int a, int b)
{
    return a == b;
}

ostream& operator<<(ostream& os, const LinkedList& ll)
{
    Node* p = ll.head;
    os << "H->";
    while (nullptr != p)
    {
        os << p->data << "->";
        p = p->next;
    }
    os << "NULL" << flush;
    return os;
}
