//
// Created by Shaunak Kulkarni on 10/19/20.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "Node.h"
using namespace std;
template <typename T>
Node<T>* BinarySearchTree<T>::getMin(Node<T>* root)
{
    while(root&& root->getLeft() != nullptr) root = root->getLeft();
    return root;
}
template <typename T>
Node<T>* BinarySearchTree<T>::search(Node<T> *root, T key) {
    if(root == nullptr){
        return nullptr;
    }
    if (root->getKey() == key){
        return root;
    }
    if (root->getKey()<key){
        return search(root->getRight(),key);
    }
    if (root->getKey()>key){
        return search(root->getLeft(),key);
    }

}

template<typename T>
Node<T>* BinarySearchTree<T>::insert(Node<T> *rootN, T key) {
    if (rootN == nullptr) {
        auto *toAdd = (Node<T>*)(malloc(sizeof(Node<T>)));
        toAdd->setKey(key);
        toAdd->setLeft(nullptr);
        toAdd->setRight(nullptr);
        return toAdd;
    }
    if (key < rootN->getKey()){
        rootN->setLeft(insert(rootN->getLeft(), key));
    }
    else {
        rootN->setRight(insert(rootN->getRight(), key));
    }
    return rootN;
}

template<typename T>
Node<T>* BinarySearchTree<T>::deleteNode(Node<T> *rootN, T key) {

    Node<T>* toDelete = search(rootN, key);
    if (toDelete->getRight() == nullptr){
        auto temp = toDelete->getLeft();
        free(toDelete);
        return temp;
    }
    if (toDelete->getRight() == nullptr){
        auto temp = toDelete->getRight();
        free(toDelete);
        return temp;
    }
    Node<T>* min = getMin(toDelete->getRight());
    toDelete->setKey(min->getKey());
    toDelete->setRight(deleteNode(toDelete->getRight(),min->getKey()));
    return toDelete;

}


template<typename T>
void BinarySearchTree<T>::printTree() {
    printTreeHelper(root);

}

template<typename T>
BinarySearchTree<T>::BinarySearchTree(Node<T> *root):root(root) {}

template<typename T>
void BinarySearchTree<T>::printTreeHelper(Node<T>* rootN) {
    if (rootN != nullptr)
    {
        printTreeHelper(rootN->getLeft());
        cout<<  rootN->getKey() << " ";
        printTreeHelper(rootN->getRight());
    }

}



template class BinarySearchTree<int>::BinarySearchTree<int>;



