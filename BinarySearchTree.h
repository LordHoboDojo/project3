//
// Created by Shaunak Kulkarni on 10/19/20.
//
#include "Node.h"
#ifndef PROJECT3_BINARYSEARCHTREE_H
#define PROJECT3_BINARYSEARCHTREE_H

template <typename T>
class BinarySearchTree {
private:
    Node<T> *root;
public:
    BinarySearchTree(Node<T> *root);

    Node<T> *getRoot() const {
        return root;
    }

    void setRoot(Node<T> *root) {
        BinarySearchTree::root = root;
    }
    Node<T>* search(Node<T> *root, T key);
    Node<T>* insert(Node<T> *rootN, T key);
    Node<T>* deleteNode(Node<T> *rootN, T key);
    Node<T>* deleteNodeHelper(Node<T>* toDelete);
    Node<T>* getMin(Node<T>* root);
    void printTree();
    void printTreeHelper(Node<T> *rootN);

};




#endif //PROJECT3_BINARYSEARCHTREE_H
