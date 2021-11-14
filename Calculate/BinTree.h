//

#ifndef START_BINTREE_H
#define START_BINTREE_H


#include "BinNode.h" //����������ڵ���

template<typename T>
class BinTree { //������ģ����
protected:
    int _size;
    BinNodePosi<T> _root; //��ģ�����ڵ�
    virtual int updateHeight(BinNodePosi<T> x); //���½ڵ�x�ĸ߶�
    void updateHeightAbove(BinNodePosi<T> x); //���½ڵ�x�������ȵĸ߶�
    int removeAt(BinNodePosi<T>); //����ɾ��
public:
    BinTree() : _size(0), _root(NULL) {} //���캯��
    ~BinTree() { if (0 < _size) remove(_root); } //��������
    int size() const { return _size; } //��ģ
    bool empty() const { return !_root; } //�п�
    BinNodePosi<T> root() const { return _root; } //����
    BinNodePosi<T> insert(T const &); //������ڵ�
    BinNodePosi<T> insert(T const &, BinNodePosi<T>); //��������
    BinNodePosi<T> insert(BinNodePosi<T>, T const &); //�����Һ���
    BinNodePosi<T> attach(BinTree<T> &, BinNodePosi<T>); //����������
    BinNodePosi<T> attach(BinNodePosi<T>, BinTree<T> &); //����������
    int remove(BinNodePosi<T>); //����ɾ��

//    BinTree<T> *secede(BinNodePosi<T>); //��������
//    template<typename VST>
//    //������
//    void travLevel(VST &visit) { if (_root) _root->travLevel(visit); } //��α���
//    template<typename VST>
//    //������
//    void travPre(VST &visit) { if (_root) _root->travPre(visit); } //�������
//    template<typename VST>
//    //������
//    void travIn(VST &visit) { if (_root) _root->travIn(visit); } //�������
//    template<typename VST>
//    //������
//    void travPost(VST &visit) { if (_root) _root->travPost(visit); } //�������

    bool operator<(BinTree<T> const &t) //�Ƚ������������в��䣩
    { return _root && t._root && lt(_root, t._root); }

    bool operator==(BinTree<T> const &t) //�е���
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
