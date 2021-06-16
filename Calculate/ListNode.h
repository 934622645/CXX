//
// Created by haoge on 2021/6/16.
//

#ifndef START_LISTNODE_H
#define START_LISTNODE_H

//#define ListNodePosi(T) ListNode<T>*


typedef int Rank;

template<typename T>
struct ListNode {
    using ListNodePosi = ListNode <T> *;
    T data;
    ListNodePosi pred;
    ListNodePosi succ;

    ListNode() = default;

    explicit ListNode(T e, ListNodePosi p = nullptr, ListNodePosi s = nullptr) :
            data{e}, pred{p}, succ{s} {}

    ListNodePosi insertAsPred(T const &e);
    ListNodePosi insertAsSucc(T const &e);
};

#endif//START_LISTNODE_H
