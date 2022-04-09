#include "linkedlist/linkedlist.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool equal(int a, int b);
bool lessthan(int a, int b);

TEST(LinkedListTests, BasicAssertions) {
  EXPECT_STRNE("hello", "world");
  EXPECT_EQ(7 * 6, 42);
}

/*int main(int argc, char** argv)
{
    LinkedList list;
    testing::InitGoogleTest(&argc, argv);
    cout << "Just created list contents: " << list << endl;
    cout << "Is 100 contained in list? " << (list.Find(100)?"yes":"no") << endl;
    cout << "Remove 100 from list" << endl;
    list.Remove(100);
    list.RemoveAll(100);
    list.Remove(100, &equal);
    list.RemoveAll(100, &equal);
    cout << "Is list empty? " << (list.IsEmpty()?"yes":"no") << endl;
    cout << "Empty list" << endl;
    list.Empty();
    cout << "Is list empty? " << (list.IsEmpty()?"yes":"no") << endl;
    cout << "Contents after emptying list: " << list << endl;
    cout << "Adding 1 to the list" << endl;
    list.Add(1);
    cout << "List contents: " << list << endl;
    cout << "Is 100 contained in list? " << (list.Find(100)?"yes":"no") << endl;
    cout << "Remove 100 from list" << endl;
    list.Remove(100);
    list.RemoveAll(100);
    list.Remove(100, &equal);
    list.RemoveAll(100, &equal);
    cout << "Is list empty? " << (list.IsEmpty()?"yes":"no") << endl;
    cout << "Is 1 contained in list? " << (list.Find(1)?"yes":"no") << endl;
    cout << "Adding more elements to the list" << endl;
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    cout << "List contents: " << list << endl;
    cout << "Remove 1 from list" << endl;
    list.Remove(1);
    cout << "List contents: " << list << endl;
    cout << "Remove 5 from list" << endl;
    list.Remove(5, &equal);
    cout << "List contents: " << list << endl;
    cout << "Remove 3 from list" << endl;
    list.Remove(3);
    cout << "List contents: " << list << endl;
    cout << "Remove 2 from list" << endl;
    list.Remove(2, &equal);
    cout << "List contents: " << list << endl;
    cout << "Remove 4 from list" << endl;
    list.Remove(4);
    cout << "List contents: " << list << endl;
    cout << "Adding items to list" << endl;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    cout << "Remove all 1s from list" << endl;
    list.RemoveAll(1, &equal);
    cout << "List contents: " << list << endl;
    cout << "Remove all 5s from list" << endl;
    list.RemoveAll(5);
    cout << "List contents: " << list << endl;
    cout << "Remove all 3s from list" << endl;
    list.RemoveAll(3, &equal);
    cout << "List contents: " << list << endl;
    cout << "Remove all 2s from list" << endl;
    list.RemoveAll(2);
    cout << "List contents: " << list << endl;
    cout << "Remove all 4s from list" << endl;
    list.RemoveAll(4, &equal);
    cout << "List contents: " << list << endl;
    cout << "Adding items to list" << endl;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    cout << "List contents: " << list << endl;
    cout << "Remove all 1s from list" << endl;
    list.RemoveAll(1, &equal);
    cout << "List contents: " << list << endl;
    cout << "Remove all 5s from list" << endl;
    list.RemoveAll(5);
    cout << "List contents: " << list << endl;
    cout << "Remove all 3s from list" << endl;
    list.RemoveAll(3, &equal);
    cout << "List contents: " << list << endl;
    cout << "Remove all 2s from list" << endl;
    list.RemoveAll(2);
    cout << "List contents: " << list << endl;
    cout << "Remove all 4s from list" << endl;
    list.RemoveAll(4, &equal);
    cout << "List contents: " << list << endl;
    cout << "Adding items to list" << endl;
    list.Add(1);
    list.Add(-2);
    list.Add(3);
    list.Add(-4);
    list.Add(5);
    list.Add(-1);
    list.Add(2);
    list.Add(-3);
    list.Add(4);
    list.Add(-5);
    list.Add(1);
    list.Add(-2);
    list.Add(3);
    list.Add(-4);
    list.Add(5);
    list.Add(-1);
    list.Add(2);
    list.Add(-3);
    list.Add(4);
    list.Add(-5);
    cout << "List contents: " << list << endl;
    cout << "Remove first found negative item" << endl;
    list.Remove(0, &lessthan);
    cout << "List contents: " << list << endl;
    cout << "Remove next negative item" << endl;
    list.Remove(0, &lessthan);
    cout << "List contents: " << list << endl;
    cout << "Remove all negative items" << endl;
    list.RemoveAll(0, &lessthan);
    cout << "List contents: " << list << endl;
    cout << "Is list empty? " << (list.IsEmpty()?"yes":"no") << endl;
    cout << "Is 100 contained in list? " << (list.Find(100)?"yes":"no") << endl;
    cout << "Remove 100 from list" << endl;
    list.Remove(100);

    return RUN_ALL_TESTS();
}*/

bool equal(int a, int b)
{
    return a == b;
}

bool lessthan(int a, int b)
{
    return a < b;
}
