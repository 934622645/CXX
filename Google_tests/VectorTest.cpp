//
// Created by 93462 on 2021/5/16.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <gtest/gtest.h>
#include <Vector.h>

class VectorTest : public testing::Test {
};

TEST_F(VectorTest, constructor) {
    int l[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
    Vector<int> a; // 默认构造
    Vector<int> a1(l, 10); // 拷贝构造-1
    Vector<int> a2(l, 4, 10); // 拷贝构造-2
    Vector<int> a3(a1); // 拷贝构造-3 NOLINT(performance-unnecessary-copy-initialization)
    Vector<int> a4(a1, 4, 10); // 拷贝构造-4 NOLINT(performance-unnecessary-copy-initialization)
    a4 = a3;
#pragma clang diagnostic pop
    printf("constructor test pass\n");
}

TEST_F(VectorTest, inside){
    int l[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector<int> a(l, 10);
    a.unsort();
    a.print();
    printf("inside test pass\n");
}

