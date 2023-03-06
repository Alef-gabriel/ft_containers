#ifndef NODE_HPP
#define NODE_HPP

namespace ft {
template<typename T, class Alloc >
struct Node {
    T   *value;
    Node* right;
    Node* left;
    int color;
    Node* parent;
    Alloc _alloc;

    Node() : value(NULL), right(NULL), left(NULL), color(1), parent(NULL) {}

    Node(T const &copy) : right(NULL), left(NULL), color(1), parent(NULL) {
        value = _alloc.allocate(1);
        _alloc.construct(value, copy);
    }

    Node &operator=(Node const &copy) {
        if (this != &copy) {
            if (value)
                _alloc.deallocate(value, 1);
            left = copy.left;
            right = copy.right;
            color = copy.color;
            parent = copy.parent;
            value = _alloc.allocate(1);
            _alloc.construct(value, *copy.value);
        }
        return (*this);
    }

  ~Node() {}
};
}
#endif