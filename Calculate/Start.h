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

    /**
     * O(n)-O(n)
     * @param set 求解集合
     * @param n 集合数量
     * @return
     */
    static int sum_re(int *set, int n);

    /**
     * O(n)-O(log(n))
     * @param set 求解集合
     * @param lo 集合下界
     * @param hi 集合上界
     * @return
     */
    static int sum_re_di(int *set, int lo, int hi);

    /**
     * O(n)-O(1)
     * @param set 求解集合
     * @param n 集合数量
     * @return
     */
    static int sum_it(const int *set, int n);

    static void reverse_re(int set[], int lo, int hi);

    static void reverse_it(int set[], int lo, int hi);

    static int64_t power2_re(int n);

    static int64_t power2_it(int n);

    /**
     * O(2^n)-O(n)
     * @param n
     * @return
     */
    static int64_t fib_re(int n);

    /**
 * O(n)-O(n)
 * @param n
 * @param p
 * @return
 */
    static int64_t fib_re_li(int n, int64_t &p);

    /**
     * O(n)-O(1)
     * @param n
     * @return
     */
    static int64_t fib_it(int n);
};


#endif //START_START_H
