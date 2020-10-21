//
// Created by Shaunak Kulkarni on 10/19/20.
//

#ifndef PROJECT3_NODE_H
#define PROJECT3_NODE_H

#include <cstdlib>

template <class T>
class Node {

public:
    Node() {
        right = nullptr;
        left = nullptr;
    }

    Node<T> *getRight() const {
        return right;
    }

    void setRight(Node<T> *right) {
        Node::right = right;
    }

    Node<T> *getLeft() const {
        return left;
    }

    void setLeft(Node<T> *left) {
        Node::left = left;
    }

    T getKey() const {
        return key;
    }

    void setKey(T key) {
        Node::key = key;
    }

private:
    Node<T> *right;
    Node<T> *left;
    T key;

public:
    Node(T key) : key(key) {
        right = nullptr;
        left = nullptr;
    }


};


#endif //PROJECT3_NODE_H
