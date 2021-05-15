//
// Created by 93462 on 2021/5/13.
//

#include "Start.h"
#include <vector>

using namespace std;

int Start::add(int a, int b) {
    return a + b;
}

void Start::bubble_sort(int *set, int n) {
    for (bool status = false; (status = !status); n--) {
        for (int i = 1; i < n; ++i) {
            if (set[i - 1] > set[i]) {
                swap(set[i - 1], set[i]);
                status = false;
            }
        }
    }
}

int Start::sum_re(int *set, int n) {
    return n < 1 ? 0 : set[n - 1] + sum_re(set, n - 1);
}

int Start::sum_it(const int *set, int n) {
    int sum = 0;
    for (; n > 0; n--) {
        sum += set[n - 1];
    }
    return sum;
}

void Start::reverse_re(int *set, int lo, int hi) {
    if (lo < hi) {
        swap(set[lo], set[hi]);
        reverse_re(set, lo + 1, hi - 1);
    }
}

void Start::reverse_it(int *set, int lo, int hi) {
    while (lo < hi) swap(set[lo++], set[hi--]);
}

inline int64_t sqr(int64_t a) { return a * a; }

int64_t Start::power2_re(int n) { // NOLINT(readability-convert-member-functions-to-static)
    if (n == 0)return 1;
    return (n & 1) ? sqr(power2_re(n >> 1)) << 1 : sqr(power2_re(n >> 1));
}

int64_t Start::power2_it(int n) {
    if (n == 0) {
        return 1;
    }
    int64_t result = 1;
    int64_t bit = 2;
    for (; n > 0; n >>= 1, bit = sqr(bit)) {
        if (n & 1) result *= bit;
    }
    return result;
}







