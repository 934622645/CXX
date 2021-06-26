#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"

//
// Created by haoge on 2021/6/16.
//

#include <gtest/gtest.h>
#include "List.h"
class ListTest : public testing::Test {
};

TEST_F(ListTest , base) {
    List<int> list;
    List<int> list1{list};
    list.insertAsFirst(10);
    list.insertAsLast(11);
    List<int> list2(list1, 1, 1);
    ASSERT_EQ(10, list.find(10)->data);
    ASSERT_EQ(10, list1.find(10)->data);
    ASSERT_EQ(10, list2.find(10)->data);
    ASSERT_EQ(11, list.find(11)->data);
    ASSERT_EQ(11, list1.find(11)->data);
}

