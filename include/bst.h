// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <algorithm>

template <typename T>
class BST {
 public:
    struct Node {
        int counter = 0;
        T variable;
        Node* righ = nullptr;
        Node* leftward = nullptr;
    };

 private:
    Node* Root;
    Node* joinnode(Node*, const T&);
    int searchnode(Node* Root, const T& variable);
    int depthnode(Node* Root);

 public:
    BST();
    int depth();
    int search(T variable);
    void join(const T& variable);
    ~BST() {}
};

template <typename T>
BST<T>::BST(): Root(nullptr) {}

template <typename T>
typename BST<T>::Node* BST<T>::joinnode(Node* Root, const T& variable) {
    if (Root == nullptr) {
        Root = new Node;
        Root->counter = 1;
        Root->variable = variable;
        Root->leftward = Root->righ = nullptr;
    } else if (Root->variable > variable) {
        Root->leftward = joinnode(Root->leftward, variable);
    } else if (Root->variable < variable) {
        Root->righ = joinnode(Root->righ, variable);
    } else {
        Root->counter++;
    }
    return Root;
}

template <typename T>
void BST<T>::join(const T& variable) {
    Root = joinnode(Root, variable);
}

template <typename T>
int BST<T>::depthnode(Node* Root) {
    if (!Root) {
        return 0;
    }
    return 1 + std::max(depthnode(Root->leftward), depthnode(Root->righ));
}

template <typename T>
int BST<T>::depth() {
    return depthnode(Root) - 1;
}

template <typename T>
int BST<T>::searchnode(Node* Root, const T& variable) {
    if (Root == nullptr || Root->variable == variable) {
        return Root->counter;
    } else if (Root->variable < variable) {
        return searchnode(Root->righ, variable);
    }
    return searchnode(Root->leftward, variable);
}

template <typename T>
int BST<T>::search(T variable) {
    return searchnode(Root, variable);
}

#endif  // INCLUDE_BST_H_
