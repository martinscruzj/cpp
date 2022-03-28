#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>

using namespace std;

struct Node;

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

#endif // LINKEDLIST_HPP
