#include "circular_linked_list_test.h"

TEST_F(CircularLinkedListTest, ShouldBeEmptyInitially)
{
    ASSERT_EQ(l1_.size(), 0);
    ASSERT_TRUE(l1_.empty());
}

TEST_F(CircularLinkedListTest, ShouldPushValueToTheVeryEndOfTheList)
{
    l1_.push_back(1);
    ASSERT_EQ(l1_.at(0), 1);

    l1_.push_back(2);
    ASSERT_EQ(l1_.at(0), 1);
    ASSERT_EQ(l1_.at(1), 2);
}

TEST_F(CircularLinkedListTest, SizeShouldGrowAccordingly)
{
    for (int i = 0; i < 10; i++)
    {
        l1_.push_back(i);
        ASSERT_EQ(l1_.size(), i+1);
    }
}