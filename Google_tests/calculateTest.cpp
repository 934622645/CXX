#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc51-cpp"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cert-msc50-cpp"

#include <gtest/gtest.h>
#include <Start.h>

class CalculateTest : public testing::Test {
};

TEST_F(CalculateTest, reverse) {
    int a[]{1, 2, 3, 4, 5, 6, 7};
    int c[]{1, 2, 3, 4, 5, 6, 7};
    int b[]{7, 6, 5, 4, 3, 2, 1};
    Start::reverse_re(a, 0, 6);
    Start::reverse_it(c, 0, 6);
    for (int i = 0; i < 6; ++i) {
        EXPECT_EQ(a[i], b[i]);
        EXPECT_EQ(c[i], b[i]);
    }
}

TEST_F(CalculateTest, sum) {
    int a[]{1, 2, 3, 4, 5, 6};
    int b[]{0};
    int c[]{-1, -2, -3, 3, 2, 1};
    Start object{};
    EXPECT_EQ(21, object.sum_re(a, 6));
    EXPECT_EQ(21, object.sum_it(a, 6));
    EXPECT_EQ(0, object.sum_re(b, 1));
    EXPECT_EQ(0, object.sum_it(b, 1));
    EXPECT_EQ(0, object.sum_re(c, 6));
    EXPECT_EQ(0, object.sum_it(c, 6));

}

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
    time_t start_time, end_time;
    start_time = time(nullptr);
    Start::bubble_sort(a, length);
    end_time = time(nullptr);
    for (int i = 1; i < length; ++i) {
        EXPECT_TRUE(a[i - 1] <= a[i]);

    }
    std::cout << "bubble_sort " << length
              << " speed time "
              << end_time - start_time << std::endl;
}

TEST_F(CalculateTest, power2) {
    EXPECT_EQ(1073741824, Start::power2_re(30));
    EXPECT_EQ(1073741824, Start::power2_it(30));
    EXPECT_EQ(8, Start::power2_it(3));
    EXPECT_EQ(16, Start::power2_it(4));
}
