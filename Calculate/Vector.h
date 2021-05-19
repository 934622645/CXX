#pragma clang diagnostic push

//
// Created by 93462 on 2021/5/16.
//

#ifndef START_VECTOR_H
#define START_VECTOR_H

using namespace std;
using Rank = int; //秩
#define DEFAULT_CAPACITY  3 //默认的初始容量（实际应用中可设置为更大）

#include <vector>

template<typename T>
class Vector { //向量模板类
protected:
    Rank _size;
    int _capacity;
    T *_elem; //规模、容量、数据区
    // O(n)-O(n)
    void copyFrom(T const *A, Rank lo, Rank hi); //复制数组区间A[lo, hi)
    // O(1)-O(1) - share
    void expand(); //空间不足时扩容
    // O(1)-O(1) - share
    void shrink(); //装填因子过小时压缩
//    bool bubble ( Rank lo, Rank hi ); //扫描交换
//    void bubbleSort ( Rank lo, Rank hi ); //起泡排序算法
//    Rank maxItem ( Rank lo, Rank hi ); //选取最大元素
//    void selectionSort ( Rank lo, Rank hi ); //选择排序算法
//    void merge ( Rank lo, Rank mi, Rank hi ); //归并算法
//    void mergeSort ( Rank lo, Rank hi ); //归并排序算法
//    void heapSort ( Rank lo, Rank hi ); //堆排序（稍后结合完全堆讲解）
//    Rank partition ( Rank lo, Rank hi ); //轴点构造算法
//    void quickSort ( Rank lo, Rank hi ); //快速排序算法
//    void shellSort ( Rank lo, Rank hi ); //希尔排序算法
public:
    // O(n)-O(n) 构造函数
    explicit Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) //容量为c、规模为s、所有元素初始为v
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v);
    } //s<=c NOLINT(bugprone-suspicious-semicolon)
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"

    // O(n)-O(n)
    Vector(T const *A, Rank n) { copyFrom(A, 0, n); } //数组整体复制
    // O(n)-O(n)
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); } //区间
    // O(n)-O(n)
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); } //向量整体复制
    // O(n)-O(n)
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } //区间
#pragma clang diagnostic pop

    // 析构函数
    ~Vector() { delete[] _elem; } //释放内部空间
    void test();

    void print();

    // 只读访问接口
    Rank size() const { return _size; } //规模
    bool empty() const { return !_size; } //判空
//    Rank find ( T const& e ) const { return find ( e, 0, _size ); } //无序向量整体查找
//    Rank find ( T const& e, Rank lo, Rank hi ) const; //无序向量区间查找
//    Rank search ( T const& e ) const //有序向量整体查找
//    { return ( 0 >= _size ) ? -1 : search ( e, 0, _size ); }
//    Rank search ( T const& e, Rank lo, Rank hi ) const; //有序向量区间查找
//    // 可写访问接口
    T &operator[](Rank r); //重载下标操作符，可以类似于数组形式引用各元素
//    const T& operator[] ( Rank r ) const; //仅限于做右值的重载版本

    // O(n)-O(n)
    Vector<T> &operator=(Vector<T> const &); //重载赋值操作符，以便直接克隆向量
//    T remove ( Rank r ); //删除秩为r的元素
//    int remove ( Rank lo, Rank hi ); //删除秩在区间[lo, hi)之内的元素
//    Rank insert ( Rank r, T const& e ); //插入元素
//    Rank insert ( T const& e ) { return insert ( _size, e ); } //默认作为末元素插入
//    void sort ( Rank lo, Rank hi ); //对[lo, hi)排序
//    void sort() { sort ( 0, _size ); } //整体排序
//    void unsort ( Rank lo, Rank hi ); //对[lo, hi)置乱
//    void unsort() { unsort ( 0, _size ); } //整体置乱
//    int deduplicate(); //无序去重
//    int uniquify(); //有序去重
//    // 遍历
//    void traverse ( void (* ) ( T& ) ); //遍历（使用函数指针，只读或局部性修改）
//    template <typename VST> void traverse ( VST& ); //遍历（使用函数对象，可全局性修改）
};

template<typename T>
void Vector<T>::copyFrom(const T *A, Rank lo, Rank hi) {
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi) _elem[_size++] = A[lo++];
}

template<typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &v) {
    if (&v == this) return *this;
    if (_elem) delete[] _elem;
    copyFrom(v._elem, 0, v._size);
    return *this;
}

template<typename T>
void Vector<T>::expand() {
    if (_size < _capacity) return;
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY;
    T *oleElem = _elem;
    _elem = new T[_capacity <<= 1];
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oleElem[i];
    }
    delete[] oleElem;
}

template<typename T>
void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return;
    if (_size << 2 > _capacity) return;
    T *oleElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; ++i) {
        _elem[i] = oleElem[i];
    }
    delete[] oleElem;
}

template<typename T>
void Vector<T>::test() {
    this->_size = 3;
    this->expand();
    this->_size = 1;
    this->shrink();
}

template<typename T>
T &Vector<T>::operator[](Rank r) {
    return _elem[r];
}

template<typename T>
void Vector<T>::print() {
    for (int i = 0; i < _size; ++i) std::cout << _elem[i] << '\t';
    std::cout << '\n';
}



//Vector

template<typename T>
void permute(Vector<T> &V) {
    for (int i = V.size(); i > 0; i--) swap(V[i - 1], V[rand() % i]); // NOLINT(cert-msc50-cpp)
}

#endif //START_VECTOR_H

