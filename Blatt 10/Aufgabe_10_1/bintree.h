#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "eidpliste.h"

using namespace std;

template<typename T>
class BinTree {
private:
    struct Node {
        T data;
        Node *left, *right; // linker und rechter Unterbaum
    };

    Node *root; // Wurzel

    bool isElement(Node *node, T data) {
        if (node == nullptr)
            return false;
        if (node->data == data)
            return true;
        if (node->data < data)
            return isElement(node->right, data);
        return isElement(node->left, data);
    }

    void clear(Node *node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    Node *insert(Node *node, T data) {
        if (node == nullptr) {
            node = new Node;
            node->data = data;
            node->left = node->right = nullptr;
            return node;
        }
        if (node->data < data)
            node->right = insert(node->right, data);
        else if (node->data > data)
            node->left = insert(node->left, data);
        return node;
    }

    // Aufgabe 1a)
    void preOrder(Node *node) {
        // hier Code einfuegen
    }

    // Aufgabe 1a)
    void inOrder(Node *node) {
        // hier Code einfuegen
    }

    // Aufgabe 1a)
    void postOrder(Node *node) {
        // hier Code einfuegen
    }

    // Aufgabe 1b)
    int height(Node *node) {
        // hier Code einfuegen
        return -1;
    }

    // Aufgabe 1c)
    int count(Node *node) {
        // hier Code einfuegen
        return -1;
    }

    // Aufgabe 1d)
    void range(Node *node, T min, T max) {
        // hier Code einfuegen
    }

public:
    BinTree() : root(nullptr) {
    }

    ~BinTree() {
        clear(root);
    }

    void clear() {
        clear(root);
        root = nullptr;
    }

    void insert(T x) {
        root = insert(root, x);
    }

    bool isElement(T x) {
        return isElement(root, x);
    }

    T rootData() {
        return root->data;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }

    int height() {
        return height(root);
    }

    int count() {
        return count(root);
    }

    void range(T min, T max) {
        range(root, min, max);
    }

    // Aufgabe 1e)
    void rotateLeft() {
        // hier Code einfuegen
    }
};


#endif /* BINTREE_H */
