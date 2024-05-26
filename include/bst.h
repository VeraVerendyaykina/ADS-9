// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
template<typename T>
class BST {
 private:
    struct Node {
        T value;
        int count;
        Node *right, *left;
    };
    Node* root;
    Node* addNode(Node* root, const T& value) {
        if (!root) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
         } else if (root->value > value) {
             root->left = addNode(root->left, value);
         } else if (root->value < value) {
             root->right = addNode(root->right, value);
         } else {
             ++root->count;
         }
         return root;
    }
    int depth(Node* root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(depth(root->left), depth(root->right));
    }

 public:
    void addVal(T value) {
        root = addNode(root, value);
    }
    int depth() {
        return depth(root) - 1;
    }
    int search(const T& value) {
        Node* copy = root;
        while (copy && copy->value != value) {
            if (copy->value > value)
                copy = copy->left;
            else
                copy = copy->right;
        }
        if (!copy) {
            return 0;
        }
        return copy->count;
    }
    BST() : root(nullptr) {}
    BST<std::string> createTree(const char* filename);
};
#endif  // INCLUDE_BST_H_
