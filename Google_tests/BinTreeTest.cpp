#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
//
// Created by 93462 on 2021/11/14.
//

#include <gtest/gtest.h>
#include <BinTree.h>

class BinTreeTest : public ::testing::Test {
};

TEST_F(BinTreeTest, insert_and_attach) {
    BinTree<int> tree;
    tree.insert(20);
    tree.insert(10, tree.root());
    tree.insert(tree.root(), 15);

    BinTree<int> tree1;
    BinTree<int> tree2;
    BinTree<int> tree3;

    tree1.insert(1);
    tree2.insert(2);
    tree3.insert(3);
    tree1.attach(tree1.root(), tree2);
    tree1.attach(tree3, tree1.root());
    BinNodePosi<int> p = tree1.root()->rc;
    tree1.remove(tree1.root()->rc);
}

#pragma clang diagnostic pop