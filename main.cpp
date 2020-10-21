#include <iostream>
#include "BinarySearchTree.h"
using namespace std;
int main() {
    BinarySearchTree<int> tree(nullptr);
    tree.setRoot(tree.insert(tree.getRoot(),9));
    tree.insert(tree.getRoot(), 10);
    tree.insert(tree.getRoot(), 5);
    tree.insert(tree.getRoot(), 16);
    tree.deleteNode(tree.getRoot(),16);
    tree.printTree();
    return 0;
}
