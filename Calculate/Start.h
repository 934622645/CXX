//
// Created by 93462 on 2021/5/13.
//

#ifndef START_START_H
#define START_START_H

#include <cstdint>

class Start {
public:
    static int add(int a, int b);

    static void bubble_sort(int set[], int n);

    static int sum_re(int *set, int n);

    static int sum_it(const int *set, int n);

    static void reverse_re(int set[], int lo, int hi);

    static void reverse_it(int set[], int lo, int hi);

    static int64_t power2_re(int n);

    static int64_t power2_it(int n);
};


#endif //START_START_H
