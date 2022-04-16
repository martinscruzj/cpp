#include "linkedlist/linkedlist.hpp"
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

bool equal(int a, int b);
bool lessthan(int a, int b);

class LinkedListTestFixture : public ::testing::Test {
protected:
   void SetUp() override {

   }

   void TearDown() override {

   }
   LinkedList list;
};

TEST_F(LinkedListTestFixture, SeveralTests) {
   // Verify initial contents of just created list
   std::stringstream ss;
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->NULL");
   // List should not contain 100
   EXPECT_FALSE(list.Find(100));
   // Removing non-existing elements
   list.Remove(100);
   list.RemoveAll(100);
   list.Remove(100, &equal);
   list.RemoveAll(100, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->NULL");
   // The list should be empty
   EXPECT_TRUE(list.IsEmpty());
   // Empty list and check
   list.Empty();
   EXPECT_TRUE(list.IsEmpty());
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->NULL");
   // Add 1 to the list
   list.Add(1);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->1->NULL");
   EXPECT_FALSE(list.Find(100));
   list.Remove(100);
   list.RemoveAll(100);
   list.Remove(100, &equal);
   list.RemoveAll(100, &equal);
   EXPECT_FALSE(list.IsEmpty());
   EXPECT_TRUE(list.Find(1));
   // Adding more elements to the list
   list.Add(2); list.Add(3); list.Add(4); list.Add(5);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->5->4->3->2->1->NULL");
   list.Remove(1);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->5->4->3->2->NULL");
   list.Remove(5, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->3->2->NULL");
   list.Remove(3, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->2->NULL");
   list.Remove(2, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->NULL");
   list.Remove(4, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->NULL");
   // Adding elements to the list
   list.Add(1); list.Add(2); list.Add(3); list.Add(4); list.Add(5);
   list.RemoveAll(1, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->5->4->3->2->NULL");
   list.RemoveAll(5);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->3->2->NULL");
   list.RemoveAll(3, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->2->NULL");
   list.RemoveAll(2);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->NULL");
   list.RemoveAll(4, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->NULL");
   // Adding items to the list
   list.Add(1); list.Add(2); list.Add(3); list.Add(4); list.Add(5);
   list.Add(1); list.Add(2); list.Add(3); list.Add(4); list.Add(5);
   list.Add(1); list.Add(2); list.Add(3); list.Add(4); list.Add(5);
   list.Add(1); list.Add(2); list.Add(3); list.Add(4); list.Add(5);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->5->4->3->2->1->"
                                     "5->4->3->2->1->"
                                     "5->4->3->2->1->"
                                     "5->4->3->2->1->NULL");
   list.RemoveAll(1, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->5->4->3->2->"
                                     "5->4->3->2->"
                                     "5->4->3->2->"
                                     "5->4->3->2->NULL");
   list.RemoveAll(5);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->3->2->"
                                     "4->3->2->"
                                     "4->3->2->"
                                     "4->3->2->NULL");
   list.RemoveAll(3, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->2->"
                                     "4->2->"
                                     "4->2->"
                                     "4->2->NULL");
   list.RemoveAll(2);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->"
                                     "4->"
                                     "4->"
                                     "4->NULL");
   list.RemoveAll(4, &equal);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->NULL");
   // Add items to list
   list.Add( 1); list.Add(-2); list.Add( 3); list.Add(-4); list.Add( 5);
   list.Add(-1); list.Add( 2); list.Add(-3); list.Add( 4); list.Add(-5);
   list.Add( 1); list.Add(-2); list.Add( 3); list.Add(-4); list.Add( 5);
   list.Add(-1); list.Add( 2); list.Add(-3); list.Add( 4); list.Add(-5);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->-5->4->-3->2->-1->"
                                     "5->-4->3->-2->1->"
                                     "-5->4->-3->2->-1->"
                                     "5->-4->3->-2->1->NULL");
   // Remove first found negative item
   list.Remove(0, &lessthan);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->-3->2->-1->"
                                     "5->-4->3->-2->1->"
                                     "-5->4->-3->2->-1->"
                                     "5->-4->3->-2->1->NULL");
   // Remove next negative item
   list.Remove(0, &lessthan);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->2->-1->"
                                     "5->-4->3->-2->1->"
                                     "-5->4->-3->2->-1->"
                                     "5->-4->3->-2->1->NULL");
   // Remove all negative items
   list.RemoveAll(0, &lessthan);
   ss.str(""); // Clear stream
   ss << list;
   EXPECT_STREQ(ss.str().c_str(), "H->4->2->"
                                     "5->3->1->"
                                     "4->2->"
                                     "5->3->1->NULL");
   EXPECT_FALSE(list.IsEmpty());
   EXPECT_FALSE(list.Find(100));
   list.Remove(100);
   list.RemoveAll(100, &equal);
   EXPECT_FALSE(list.Find(100));
   EXPECT_FALSE(list.IsEmpty());
}

bool equal(int a, int b)
{
    return a == b;
}

bool lessthan(int a, int b)
{
    return a < b;
}
