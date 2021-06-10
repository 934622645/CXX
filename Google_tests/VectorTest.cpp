//
// Created by 93462 on 2021/5/16.
//
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <gtest/gtest.h>
#include <Vector.h>
#include <numeric>

class VectorTest : public testing::Test {
};

TEST_F(VectorTest, constructor) {
    int l[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
    Vector<int> a;             // 默认构造
    Vector<int> a1(l, 10);     // 拷贝构造-1
    Vector<int> a2(l, 4, 10);  // 拷贝构造-2
    Vector<int> a3(a1);        // 拷贝构造-3 NOLINT(performance-unnecessary-copy-initialization)
    Vector<int> a4(a1, 4, 10); // 拷贝构造-4 NOLINT(performance-unnecessary-copy-initialization)
    a4 = a3;
#pragma clang diagnostic pop
    printf("constructor test pass\n");
}

TEST_F(VectorTest, inside) {
    int l[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector<int> a(l, 10);
    a.unsort();
    a.print();
    printf("inside test pass\n");
}

void print(int &e) {
    std::cout << e << '\t';
}

TEST_F(VectorTest, CRUD) {
    int l[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Vector<int> a(l, 10);
    ASSERT_EQ(8, a.insert(8, 11));
    ASSERT_EQ(8, a.find(11));
    ASSERT_EQ(11, a.remove(8));
    ASSERT_EQ(-1, a.find(11));
    ASSERT_EQ(5, a.insert(5, 3));
    ASSERT_EQ(1, a.disordered());
    ASSERT_EQ(5, a.find(3));
    ASSERT_EQ(1, a.deduplicate());
    ASSERT_EQ(2, a.insert(2, 3));
    ASSERT_EQ(1, a.uniquify());
    a.traverse(print);
}

TEST_F(VectorTest, Search) {

    vector<int> ll(1000);
    iota(ll.begin(), ll.end(), 1);
    Vector<int> a(ll.data(), 1000);
    ASSERT_EQ(8, a.search(9, 0, 9));
    ASSERT_EQ(8, binSearch(ll.data(), 9, 0, 9));
    ASSERT_EQ(3, a.fibSearch(4, 0, 9));
    ASSERT_EQ(3, a.binSearch1(4, 0, 9));
    ASSERT_EQ(0, a.binSearch1(1, 0, 9));
    ASSERT_EQ(-1, a.binSearch1(-1, 0, 9));

}


TEST_F(VectorTest, Sort) {
    vector<int> ll(1000);
    iota(ll.begin(), ll.end(), 1);
    Vector<int> a(ll.data(), 1000);
    a.unsort();
    Rank len = a.size() - 1;
    a.bubbleSort(0, len);
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(i, a.binSearch1(i+1, 0, len));
    }
    a.unsort();
    a.mergeSort(0, len);
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(i, a.binSearch1(i+1, 0, len));
    }
}

// fibonacci test
TEST_F(VectorTest, Fibonacci) {
    Fib fib(5);
    ASSERT_EQ(5, fib.next());
    ASSERT_EQ(8, fib.next());
    ASSERT_EQ(5, fib.prev());
    ASSERT_EQ(3, fib.prev());
}
