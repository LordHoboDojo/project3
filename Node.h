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

    void setRight(Node<T> *right1) {
        Node::right = right1;
    }

    Node<T> *getLeft() const {
        return left;
    }

    void setLeft(Node<T> *left1) {
        Node::left = left1;
    }

    T getPayload() const {
        return payload;
    }

    void setPayload(T key) {
        Node::payload = key;
    }

private:
    Node<T> *right;
    Node<T> *left;
    T payload;

public:
    Node(T key) : payload(key) {
        right = nullptr;
        left = nullptr;
    }


};


#endif //PROJECT3_NODE_H
