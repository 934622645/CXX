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
