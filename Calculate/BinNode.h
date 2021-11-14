//
// Created by 93462 on 2021/11/14.
//

#ifndef START_BINNODE_H
#define START_BINNODE_H


#if defined( DSA_REDBLACK )
#define stature(p) ((p) ? (p)->height : 0) //������ڵ�ĺڸ߶ȣ�NULL�����ⲿ�ڵ㣬��Ӧ��0��
#else
#define stature(p) ((p) ? (p)->height : -1) //����BST�нڵ�ĸ߶ȣ�NUll������������Ӧ��-1��
#endif
typedef enum {
    RB_RED, RB_BLACK
} RBColor; //�ڵ���ɫ
template<typename T>
struct BinNode;
template<typename T> using BinNodePosi = BinNode<T> *; //�ڵ�λ��
template<typename T>
struct BinNode { //�������ڵ�ģ����
    // ��Ա��Ϊ���������ͳһ���ţ����߿ɸ�����Ҫ��һ����װ��
    T data; //��ֵ
    BinNodePosi<T> parent, lc, rc; //���ڵ㼰���Һ���

    int height; //�߶ȣ�ͨ�ã�
    int npl; //Null Path Length����ʽ�ѣ�Ҳ��ֱ����height���棩
    RBColor color; //��ɫ���������

// ���캯��
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {};

    BinNode(T e, BinNodePosi<T> p = NULL, BinNodePosi<T> lc = NULL, BinNodePosi<T> rc = NULL,
            int h = 0, int l = 1, RBColor c = RB_RED) :
            data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    // �����ӿ�
//    int size(); //ͳ�Ƶ�ǰ�ڵ����������༴����Ϊ���������Ĺ�ģ

    BinNodePosi<T> insertAsLC(T const &); //��Ϊ��ǰ�ڵ�����Ӳ����½ڵ�

    BinNodePosi<T> insertAsRC(T const &); //��Ϊ��ǰ�ڵ���Һ��Ӳ����½ڵ�

//    BinNodePosi<T> succ(); //ȡ��ǰ�ڵ��ֱ�Ӻ��

//    template<typename VST>
//    void travLevel(VST &); //������α���
//    template<typename VST>
//    void travPre(VST &); //�����������
//    template<typename VST>
//    void travIn(VST &); //�����������
//    template<typename VST>
//    void travPost(VST &); //�����������

    // �Ƚ������е�����������һ���������в��䣩
    bool operator<(BinNode const &bn) { return data < bn.data; } //С��
    bool operator==(BinNode const &bn) { return data == bn.data; } //����
};

template<typename T>
BinNodePosi<T> BinNode<T>::insertAsLC(const T &e) {
    return lc = new BinNode (e, this);
}

template<typename T>
BinNodePosi<T> BinNode<T>::insertAsRC(const T &e) {
    return rc = new BinNode (e, this);
}

 /******************************************************************************************
  * BinNode״̬�����ʵ��ж�
  ******************************************************************************************/
 #define IsRoot(x) ( ! ( (x).parent ) )
 #define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
 #define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
 #define HasParent(x) ( ! IsRoot(x) )
 #define HasLChild(x) ( (x).lc )
 #define HasRChild(x) ( (x).rc )
 #define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //����ӵ��һ������
 #define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //ͬʱӵ����������
 #define IsLeaf(x) ( ! HasChild(x) )

 /******************************************************************************************
  * ��BinNode�����ض���ϵ�Ľڵ㼰ָ��
  ******************************************************************************************/
 #define sibling( p ) ( IsLChild( * (p) ) ? (p)->parent->rc : (p)->parent->lc ) /*�ֵ�*/
 #define uncle( x ) ( sibling( (x)->parent ) ) /*����*/
 #define FromParentTo( x ) /*���Ը��׵�����*/ \
    ( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )



#endif //START_BINNODE_H
