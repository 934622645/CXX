//
// Created by haoge on 2021/6/16.
//

#ifndef START_LISTNODE_H
#define START_LISTNODE_H

//#define ListNodePosi(T) ListNode<T>*


typedef int Rank;

template<typename T>
class ListNode {
public:
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

template<typename T>
typename ListNode<T>::ListNodePosi ListNode<T>::insertAsPred(const T &e) {
    auto add = new ListNode<T>(e, pred, this);
    pred->succ = add;
    pred = add;
    return add;
}

template<typename T>
typename ListNode<T>::ListNodePosi ListNode<T>::insertAsSucc(const T &e) {
    auto add = new ListNode<T>(e, this, succ);
    succ->pred = add;
    succ = add;
    return add;
}

#endif//START_LISTNODE_H
