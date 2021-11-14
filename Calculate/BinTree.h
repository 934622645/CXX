//

#ifndef START_BINTREE_H
#define START_BINTREE_H


#include "BinNode.h" //引入二叉树节点类

template<typename T>
class BinTree { //二叉树模板类
protected:
    int _size;
    BinNodePosi<T> _root; //规模、根节点
    virtual int updateHeight(BinNodePosi<T> x); //更新节点x的高度
    void updateHeightAbove(BinNodePosi<T> x); //更新节点x及其祖先的高度
    int removeAt(BinNodePosi<T>); //子树删除
public:
    BinTree() : _size(0), _root(NULL) {} //构造函数
    ~BinTree() { if (0 < _size) remove(_root); } //析构函数
    int size() const { return _size; } //规模
    bool empty() const { return !_root; } //判空
    BinNodePosi<T> root() const { return _root; } //树根
    BinNodePosi<T> insert(T const &); //插入根节点
    BinNodePosi<T> insert(T const &, BinNodePosi<T>); //插入左孩子
    BinNodePosi<T> insert(BinNodePosi<T>, T const &); //插入右孩子
    BinNodePosi<T> attach(BinTree<T> &, BinNodePosi<T>); //接入左子树
    BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T> &); //接入右子树
    int remove(BinNodePosi<T>); //子树删除

//    BinTree<T> *secede(BinNodePosi<T>); //子树分离
//    template<typename VST>
//    //操作器
//    void travLevel(VST &visit) { if (_root) _root->travLevel(visit); } //层次遍历
//    template<typename VST>
//    //操作器
//    void travPre(VST &visit) { if (_root) _root->travPre(visit); } //先序遍历
//    template<typename VST>
//    //操作器
//    void travIn(VST &visit) { if (_root) _root->travIn(visit); } //中序遍历
//    template<typename VST>
//    //操作器
//    void travPost(VST &visit) { if (_root) _root->travPost(visit); } //后序遍历

    bool operator<(BinTree<T> const &t) //比较器（其余自行补充）
    { return _root && t._root && lt(_root, t._root); }

    bool operator==(BinTree<T> const &t) //判等器
    { return _root && t._root && (_root == t._root); }
};

template<typename T>
int BinTree<T>::updateHeight(BinNodePosi<T> x) {
    return x->height = 1 +
                       (stature(x->lc) > stature(x->rc) ? stature(x->lc) : stature(x->rc));
}

template<typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi<T> x) {
    while (x) {
        updateHeight(x);
        x = x->parent;
    }
}

//
// Created by 93462 on 2021/11/14.
template<typename T>
BinNodePosi<T> BinTree<T>::insert(const T &e) {
    if (_size == 0) {
        _size = 1;
        return _root = new BinNode<T>(e);
    }
    return nullptr;
}

template<typename T>
BinNodePosi<T> BinTree<T>::insert(const T &e, BinNodePosi<T> x) {
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

template<typename T>
BinNodePosi<T> BinTree<T>::insert(BinNodePosi<T> x, const T &e) {
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

template<typename T>
BinNodePosi<T> BinTree<T>::attach(BinTree<T> &S, BinNodePosi<T> x) {
    if ((x->lc = S._root)) x->lc->parent = x;
    _size += S._size;
    updateHeightAbove(x);
    S._root = nullptr;
    S._size = 0;
    return x;
}


template<typename T>
BinNodePosi<T> BinTree<T>::attach(BinNodePosi<T> x, BinTree<T> &S) {
    if ((x->rc = S._root)) x->rc->parent = x;
    _size += S._size;
    updateHeightAbove(x);
    S._root = nullptr;
    S._size = 0;
    return x;
}

template<typename T>
int BinTree<T>::remove(BinNodePosi<T> x) {
    FromParentTo(*x) = nullptr;
    updateHeightAbove(x);
    int n = removeAt(x);
    _size -= n;
    return n;
}

template<typename T>
int BinTree<T>::removeAt(BinNodePosi<T> x) {
    if(!x) return 0;
    int n = 1 + removeAt(x->rc) + removeAt(x->lc);
    delete x;
    return n;
}


//BinTree

#endif //START_BINTREE_H
