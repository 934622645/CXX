#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"
#include <gtest/gtest.h>
#include <Start.h>

class CalculateTest : public testing::Test {
};


TEST_F(CalculateTest, BasicAssertions) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(7 * 6, 42);
    EXPECT_EQ(3, Start().add(1, 2));
}

TEST_F(CalculateTest, bubble_sort) {
    srand((unsigned int) time(nullptr));
    const int length = 1000;
    int a[length];
    for (int &i : a) {
        i = rand() % 1000000;
    }
    Start demo{};
    time_t start_time, end_time;
    start_time = time(nullptr);
    demo.bubble_sort(a, length);
    end_time = time(nullptr);
    for (int i = 1; i < length; ++i) {
        EXPECT_TRUE(a[i - 1] <= a[i]);

    }
    std::cout << "bubble_sort " << length
              << " speed time "
              << end_time - start_time << std::endl;
}


