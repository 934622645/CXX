#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
//
// Created by haoge on 2021/6/16.
//

#ifndef START_LIST_H
#define START_LIST_H


#include "ListNode.h" //引入列表节点类
#include <iostream>

template<typename T>
class List { //列表模板类
    using ListNodePosi = ListNode<T> *;
    using Rank = int;
private:
    int _size; // 规模
    ListNodePosi header; // 头哨兵
    ListNodePosi trailer; //尾哨兵

protected:
    void init(); //列表创建时的初始化
    int clear(); //清除所有节点

    int copyNodes(ListNodePosi, int); //复制列表中自位置p起的n项
//    ListNodePosi merge ( ListNodePosi, int, List<T> &, ListNodePosi, int ); //归并
    void mergeSort(ListNodePosi &, int); //对从p开始连续的n个节点归并排序
    void selectionSort(ListNodePosi, int); //对从p开始连续的n个节点选择排序
    // O(n*n)-O(1)
    void insertionSort(ListNodePosi, int); //对从p开始连续的n个节点插入排序
//    void radixSort(ListNodePosi, int); //对从p开始连续的n个节点基数排序

public:
    int getSize() const {
        return _size;
    }

    // 构造函数
    List() { init(); } //默认 NOLINT(cppcoreguidelines-pro-type-member-init)
    // O(n)-O(n)
    List(const List<T> &l) { // NOLINT(cppcoreguidelines-pro-type-member-init)
        this->copyNodes(l.first(), l._size);
    }

    List(const List<T> &L, Rank r, int n); //复制列表L中自第r项起的n项
    List(ListNodePosi p, int n); //复制列表中自位置p起的n项
    // 析构函数
    ~List(); //释放（包含头、尾哨兵在内的）所有节点
    // 只读访问接口

    Rank size() const { return _size; } //规模
    bool empty() const { return _size <= 0; } //判空

    // O(n)-O(1)
    ListNodePosi operator[](Rank r) const; //重载，支持循秩访问（效率低）
    // O(1)-O(1)
    ListNodePosi first() const { return header->succ; } //首节点位置
    // O(1)-O(1)
    ListNodePosi last() const { return trailer->pred; } //末节点位置
//    bool valid ( ListNodePosi p ) //判断位置p是否对外合法
//    { return p && ( trailer != p ) && ( header != p ); } //将头、尾节点等同于NULL

    // O(n)-O(1)
    ListNodePosi find(T const &e) const //无序列表查找
    { return find(e, _size, trailer); }

    // O(n)-O(1)
    ListNodePosi find(T const &e, int n, ListNodePosi p) const; //无序区间查找
    // O(n)-O(1)
    ListNodePosi search(T const &e) const //有序列表查找
    { return search(e, _size, trailer); }

    // O(n)-O(1)
    ListNodePosi search(T const &e, int n, ListNodePosi p) const; //有序区间查找
//    ListNodePosi selectMax ( ListNodePosi p, int n ); //在p及其n-1个后继中选出最大者
//    ListNodePosi selectMax() { return selectMax ( header->succ, _size ); } //整体最大者
//    // 可写访问接口

    // O(1)-O(1)
    ListNodePosi insertAsFirst(T const &e); //将e当作首节点插入
    // O(1)-O(1)
    ListNodePosi insertAsLast(T const &e); //将e当作末节点插入
    // O(1)-O(1)
    ListNodePosi insert(ListNodePosi p, T const &e); //将e当作p的后继插入
    // O(1)-O(1)
    ListNodePosi insert(T const &e, ListNodePosi p); //将e当作p的前驱插入
    T remove(ListNodePosi p); //删除合法位置p处的节点,返回被删除节点
//    void merge ( List<T> & L ) { merge ( header->succ, _size, L, L.header->succ, L._size ); } //全列表归并

    void sort(ListNodePosi p, int n); //列表区间排序
    void sort() { sort(first(), _size); } //列表整体排序

    // O(n*n)-O(1)
    int deduplicate(); //无序去重
    // O(n)-O(1)
    int uniquify(); //有序去重
//    void reverse(); //前后倒置（习题）

    // O(n)-O(1)
    void traverse(void (* )(T &)); //遍历，依次实施visit操作（函数指针，只读或局部性修改）
    // O(n)-O(1)
    template<typename VST>
    void traverse(VST &); //遍历，依次实施visit操作（函数对象，可全局性修改）
};

template<typename T>
void List<T>::init() {
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->pred = nullptr;
    header->succ = trailer;
    trailer->pred = header;
    trailer->succ = nullptr;
    _size = 0;
}

template<typename T>
typename List<T>::ListNodePosi List<T>::operator[](Rank r) const {
    ListNodePosi tp = first();
    while (r-- > 0) tp = tp->succ;
    return tp;
}

template<typename T>
typename List<T>::ListNodePosi List<T>::find(const T &e, int n, List::ListNodePosi p) const {
    while (n-- > 0)if ((p = p->pred)->data == e)return p;
    return nullptr;
}

template<typename T>
typename List<T>::ListNodePosi List<T>::insertAsFirst(const T &e) {
    _size++;
    return header->insertAsSucc(e);
}

template<typename T>
typename List<T>::ListNodePosi List<T>::insertAsLast(const T &e) {
    _size++;
    return trailer->insertAsPred(e);
}

template<typename T>
typename List<T>::ListNodePosi List<T>::insert(List::ListNodePosi p, const T &e) {
    _size++;
    return p->insertAsSucc(e);
}

template<typename T>
typename List<T>::ListNodePosi List<T>::insert(const T &e, List::ListNodePosi p) {
    _size++;
    return p->insertAsPred(e);
}

template<typename T>
int List<T>::copyNodes(List::ListNodePosi p, int n) {
    init();
    while (n--) {
        insertAsFirst(p->data);
        p = p->succ;
    }
}

template<typename T>
List<T>::List(const List<T> &L, Rank r, int n) {
    this->copyNodes(L[r], n);
}

template<typename T>
List<T>::List(List::ListNodePosi p, int n) {
    this->copyNodes(p, n);
}

template<typename T>
T List<T>::remove(List::ListNodePosi p) {
    T e = p->data;
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    delete p;
    _size--;
    return e;
}

template<typename T>
List<T>::~List() {
    clear();
    delete header;
    delete trailer;
}

template<typename T>
int List<T>::clear() {
    int oldSize = _size;
    while (_size > 0)remove(header->succ);
    return oldSize;
}

template<typename T>
int List<T>::deduplicate() {
    if (_size <= 0) return 0;
    int oldSize = _size;
    ListNodePosi p = header;
    int r = 0;
    while (trailer != (p = p->succ)) {
        ListNodePosi q = find(p->data, r, p);
        q ? remove(q) : r++;
    }
    return oldSize - _size;
}

template<typename T>
template<typename VST>
void List<T>::traverse(VST &visit) {
    for (ListNodePosi p = header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}

template<typename T>
void List<T>::traverse(void (*visit)(T &)) {
    for (ListNodePosi p = header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}

template<typename T>
int List<T>::uniquify() {
    if (_size <= 0) {
        return 0;
    }
    int oldSize = _size;
    ListNodePosi p = header;
    for (; trailer != p->succ;) {
        if (p->data == p->succ->data)remove(p->succ);
        else p = p->succ;
    }
    return oldSize - _size;
}

template<typename T>
typename List<T>::ListNodePosi List<T>::search(const T &e, int n, List::ListNodePosi p) const {
    // assert: 0<=n<=rank(p)<_size
    while (0 <= n--) {
        if ((p = p->pred)->data <= e) {
            break;
        }
    }
    return p;
}

template<typename T>
void List<T>::sort(List::ListNodePosi p, int n) {
    switch (1) {
        case 1:
            insertionSort(p, n);
            break;
        case 2:
            selectionSort(p, n);
        default:
            mergeSort(p, n);
    }
}

template<typename T>
void List<T>::insertionSort(List::ListNodePosi p, int n) {
    for (int r = 0; r < n; ++r) {
        insert(search(p->data, r, p), p->data);
        p = p->succ;
        remove(p->pred);
    }
}

template<typename T>
void List<T>::selectionSort(List::ListNodePosi, int) {

}

template<typename T>
void List<T>::mergeSort(List::ListNodePosi &, int) {

}


//List

// tools function
template<typename T>
void printT(T &data) {
    std::cout << data << std::endl;
}


#endif //START_LIST_H

//#pragma clang diagnostic pop