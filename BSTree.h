//
// Created by Shaunak Kulkarni on 10/19/20.
//
#include "Node.h"
#include "DVD.h"
#include <iostream>

#ifndef PROJECT3_BSTREE_H
#define PROJECT3_BSTREE_H

template <class T>
class BSTree {
private:
    Node<T> *root;
public:
    BSTree(Node<T> *root) {

    }

    Node<T> *getRoot() const {
        return root;
    }

    void setRoot(Node<T> *rootN1) {
        BSTree::root = rootN1;
    }
    Node<T>* search(Node<T> *rootN, T key);
    Node<T>* insert(Node<T> *rootN, T key);
    Node<T>* deleteNode(Node<T> *rootN, T payload);
    Node<T>* getMin(Node<T>* rootN);
    void printTree();
    void printTreeHelper(Node<T> *rootN);

    BSTree();
};
template<typename T>
Node<T>* BSTree<T>::search(Node<T> *rootN, T key){
    if(rootN == nullptr){
        return nullptr;
    }
    if (rootN->getPayload() == key){
        return rootN;
    }
    if (rootN->getPayload() < key){
        return search(rootN->getRight(), key);
    }
    if (rootN->getPayload() > key){
        return search(rootN->getLeft(), key);
    }
    return nullptr;
}
template<typename T>
Node<T>* BSTree<T>::insert(Node<T> *rootN, T key){
    if (rootN == nullptr) {
        auto *toAdd = new Node<T>();
        toAdd->setPayload(key);
        toAdd->setLeft(nullptr);
        toAdd->setRight(nullptr);
        return toAdd;
    }
    if (key < rootN->getPayload()){
        rootN->setLeft(insert(rootN->getLeft(), key));
    }
    else {
        rootN->setRight(insert(rootN->getRight(), key));
    }
    return rootN;
}
template<typename T>
Node<T>* BSTree<T>::deleteNode(Node<T> *rootN, T payload){
    if(rootN == nullptr){
        return nullptr;
    }
    if (payload < rootN->getPayload()){
        rootN->setLeft(deleteNode(rootN->getLeft(), payload));
    }
    else if (payload > rootN->getPayload()){
        rootN->setRight(deleteNode(rootN->getRight(), payload));
    }
    else
    {
        //Node is leaf node - just delete it and the return statement at the end will return nullptr to make its parent point to null
        if(rootN->getRight() == nullptr &&rootN->getLeft() == nullptr){
            delete rootN;
            rootN = nullptr;
        }
            //One child right = null
            // delete the node and replace it with the one child that does exist. This process works the same for right and left
        else if (rootN->getRight() == nullptr)
        {
            auto temp = rootN;
            rootN = rootN->getLeft();
            delete temp;
        }
            //One child left = null
        else if (rootN->getLeft() == nullptr)
        {
            auto temp = rootN;
            rootN = rootN->getRight();
            delete temp;
        }
        else {
            Node<T> *temp = getMin(rootN->getRight());
            rootN->setPayload(temp->getPayload());
            rootN->setRight(deleteNode(rootN->getRight(), temp->getPayload()));
        }
    }
    return rootN;

}
template<typename T>
Node<T>* BSTree<T>::getMin(Node<T>* rootN){
    if (rootN && rootN->getLeft() != nullptr) rootN = getMin(rootN->getLeft());
    return rootN;
}
template<typename T>
void BSTree<T>::printTree(){
    printTreeHelper(root);
}
template<typename T>
void BSTree<T>::printTreeHelper(Node<T> *rootN){
    if (rootN != nullptr)
    {
        printTreeHelper(rootN->getLeft());
        std::cout << rootN->getPayload() << std::endl;
        printTreeHelper(rootN->getRight());
    }
}

template<class T>
BSTree<T>::BSTree() {
    root = nullptr;

}

#endif //PROJECT3_BSTREE_H
