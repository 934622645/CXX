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
}

