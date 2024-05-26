// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
template <typename T>
class BST {
 public:
    struct Node {
        T value;
        int count;
        Node* left;
        Node* right;
    };
 private:
    Node* root;
    Node* addNode(Node*, T);
    int depthTree(Node*);
    int searchNode(Node*, T);
 public:
    BST();
    void add(T);
    int depth();
    int search(T);
};
template <typename T>
BST <T>::BST() : root(nullptr) {}
template <typename T>
typename BST <T>::Node* BST <T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->value = value;
        root->count = 1;
        root->left = root->right = nullptr;
    } else if (root->value > value) {
        root->left = addNode(root->left, value);
    } else if (root->value < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}
template <typename T>
void BST <T>::add(T value) {
    root = addNode(root, value);
}
template <typename T>
int BST<T>::depthTree(Node* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftDepth = depthTree(root->left);
        int rightDepth = depthTree(root->right);
        if (leftDepth > rightDepth) {
            return leftDepth + 1;
        } else {
            return rightDepth + 1;
        }
    }
}
template <typename T>
int BST<T>::depth() {
    return depthTree(root) - 1;
}
BST<std::string> makeTree(const char* filename);
template <typename T>
int BST<T>::searchNode(Node* root, T val) {
    if (root == nullptr)
        return 0;
    else if (root->value == val)
        return root->count;
    else if (root->value > val)
        return searchNode(root->left, val);
    else
        return searchNode(root->right, val);
}
template <typename T>
int BST<T>::search(T v) {
    return searchNode(root, v);
}

#endif  // INCLUDE_BST_H_
