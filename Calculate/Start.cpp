//
// Created by 93462 on 2021/5/13.
//

#include "Start.h"
#include <vector>
#include <stack>

using namespace std;

void test() {
    stack<int> a;

}

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

int Start::sum_re_di(int *set, int lo, int hi) {
    if (lo == hi) {
        return set[lo];
    } else {
        int mi = (lo + hi) >> 1;
        return sum_re_di(set, mi + 1, hi) + sum_re_di(set, lo, mi);
    }
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


int64_t Start::fib_re(int n) {
    return n < 2 ? n : fib_re(n - 1) + fib_re(n - 2);
}

int64_t Start::fib_re_li(int n, int64_t &p) {
    if (n == 0) {
        p = 1;
        return 0;
    } else {
        int64_t pp;
        p = fib_re_li(n - 1, pp);
        return p + pp;
    }
}

int64_t Start::fib_it(int n) {
    int64_t f = 1, g = 0;
    while (n-- > 0) {
        g += f;
        f = g - f;
    }
    return g;
}
//    if (n <= 1) {
//        return n;
//    }
//    int64_t p = 0;
//    int64_t pp = 1;
//    int64_t temp;
//    for (int i = 1; i < n; ++i) {
//        temp = p;
//        p = pp + p;
//        pp = temp;
//    }
//    return p + pp;
//}








