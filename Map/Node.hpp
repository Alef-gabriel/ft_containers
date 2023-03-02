#ifndef NODE_HPP
#define NODE_HPP

template<typename Key, typename T, class Alloc >
struct Node {
    T   value;
    Key   key;
    Node* right;
    Node* left;
    int color;
    Node* parent;
    Alloc _alloc;
};
#endif