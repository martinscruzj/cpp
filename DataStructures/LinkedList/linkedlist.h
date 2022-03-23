#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <iostream>

using namespace std;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void Add(int v);
    void Empty();
    bool IsEmpty();
    bool Find(int v);
//    void Remove(int v);
//    void RemoveAll(int v);
    void Remove(int v, bool (*criteria)(int a, int b)=nullptr);
    void RemoveAll(int v, bool (*criteria)(int a, int b)=nullptr);
    friend ostream& operator<<(ostream& os, const LinkedList& ll);

private:
    Node* head;
    static bool Equal(int a, int b);
};

#endif // LINKEDLIST_H
