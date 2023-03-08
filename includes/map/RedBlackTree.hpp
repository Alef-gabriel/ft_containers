#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP
#include <clocale>
#include <algorithm>
#include <memory>
#include "Node.hpp"

namespace ft {
template<class Key, class T, class Allocator >
class RedBlackTree
{
public:
	typedef Key	key_type;
    typedef T	value_type;
    typedef Allocator 						allocator_type;
    typedef Node< key_type, Allocator> node_type;
    typename Allocator::template rebind<node_type>::other rebind_allocator;
    node_type* root;

    RedBlackTree(): root(NULL) {}

    ~RedBlackTree() {
        clear();
    }

    node_type *insert(const key_type &value) {
        node_type *res = NULL;
        if (root) {
            while (root) {
                if (value.first < root->value->first) {
                    if (root->left) {
                        root = root->left;
                    }
                    else {
                        root->left = newNode(value, root);
                        res = root->left;
                        rebalance(root);
                        _size++;
                        break ;
                    }
                }
                else {
                    if (root->right) {
                        root = root->right;
                    }
                    else {
                        root->right = newNode(value, root);
                        res = root->right;
                        rebalance(root);
                        _size++;
                        break ;
                    }
                }
            }
        }
        else {
            root = newNode(value, root);
            res = root;
        }
        root->color = 0;
        return res;
    }

    void assign(const node_type *node) {
        if (!node)
        return;

        assign(node->left);
        if (node->value)
            insert(*(node->value));
        assign(node->right);
    }

    void clear(void) {
        delete_all(root);
        root = NULL;
    }

    node_type *search(key_type const &key) const {
        node_type *tree = root;
        node_type *res = NULL;

        if (tree) {
            while (tree)
            {
                if (key.first > tree->value->first) {
                    tree = tree->right;
                }
                else {
                    if (key.first == tree->value->first) {
                        res = tree;
                        break ;
                    }
                    tree = tree->left;
                }
            }   
        }
        return res;
    }

    bool remove(key_type const &key) {
        node_type *node = search(key);
        if (node) {
            remove(node);
            return true;
        }
        return false;
    }

    bool remove(node_type *tree) {
        if (tree) {
            node_type *u = tree;
            if (tree->parent == NULL || tree->parent->left == u) {
                tree = tree->left;
                tree = maxNode(tree);
            }
            else {
                tree = tree->right;
            }
            transplant(u, tree);
            deleteFixup(tree);
            _allocator.deallocate(u->value, 1);
            rebind_allocator.deallocate(u, 1);
            _size--;
            return true;
        }
        return false;
    }

    node_type* minNode(void) const {
        node_type *min = root;
        
        if (min) {
            while (min->left) {
                min = min->left;
            }
        }
        return min;
    }

    node_type* minNode(node_type *node) const {
        node_type *min = node;
        if (min) {
            while (min->left) {
                min = min->left;
            }
        }
        return min;
    }

    node_type* maxNode(void) const {
        node_type *max = root;
        if (max) {
            while (max->right) {
                max = max->right;
            }
        }
        return max;
    }

    node_type* maxNode(node_type *node) const {
        node_type *max = node;
        if (max) {
            while (max->right) {
                max = max->right;
            }
        }
        return max;
    }

    node_type *next(key_type const &key) const {
        node_type *node = search(key);
        if (!node)
            return (NULL);

        if (node->right != NULL)
            return (minNode(node->right));

        node_type *next = node->parent;
        while (next != NULL && node == next->right) {
            node = next;
            next = next->parent;
        }
        node = next;
        return node;
    }

    node_type *previous(key_type const &key) const {
        node_type *node = search(key);
        if (!node)
            return (NULL);

        if (node->left != NULL)
            return (maxNode(node->left));

        node_type *previous = node->parent;
        while (previous != NULL && node == previous->left) {
            node = previous;
            previous = previous->parent;
        }
        node = previous;
        return node;
    }

private:
    size_t  _size;
    allocator_type _allocator;

    void delete_all (node_type *R) {
        while (R)
        {
            if (R->left) {
                R = R->left;
            }
            else if (R->right) {
                R = R->right;
            }
            else {
                node_type *P = R->parent;
                if (P) {
                    if (P->right == R) {
                        P->right = NULL;
                    }
                    else {
                        P->left = NULL;
                    }
                }
                R->_alloc.deallocate(R->value, 1);
                rebind_allocator.deallocate(R, 1);
                R = P;
            }
        }
        
    }

    node_type* newNode(const key_type &key, node_type *parent) {
        node_type* var = rebind_allocator.allocate(1);
        rebind_allocator.construct(var, key);
        var->parent = parent;
        return var;
    }


    void rebalance(node_type* &H) {
        while (H->parent != NULL)
        {
            if (H->color == 1 && ((H->parent->left && H->parent->left->color == 1) && (H->parent->right && H->parent->right->color == 1))) {
                invertColor(H->parent);
            }
            else if (H->right != NULL && H->right->color == 1) {
                rightRotate(H);
            }
            else if (H->left != NULL && H->left->color == 1) {
                leftRotate(H);
            }
            if (H->parent != NULL)
                H = H->parent;
        }
    }

    void rightRotate(node_type* &S) {
        node_type *P = S->parent->parent != NULL ? S->parent->parent : NULL;
        if (P) {
            if (P->right == S->parent) {
                P->right = S;
            }
            else {
                P->left = S;
            }
        }
        node_type *R = S->left;
        if (R) {
            R->parent = S->parent;
        }
        S->left = S->parent;
        S->left->right = R;
        S->left->parent = S;
        S->left->color = 1;
        S->right->color = 1;
        S->color = 0;
        S->parent = P;
    }

    void leftRotate(node_type* S) {
        node_type *P = S->parent != NULL ? S->parent->parent : NULL;
        if (P) {
            if (P->right == S->parent) {
                P->right = S;
            }
            else {
                P->left = S;
            }
        }
        node_type *L = S->right;
        if (L) {
            L->parent = S->parent;
        }
        S->right = S->parent;
        S->right->parent = S;
        S->left->color = 1;
        S->right->color = 1;
        S->right->left = L;
        S->color = 0;
        S->parent = P;
    }

    void invertColor(node_type* H) {
        H->color = !H->color;
        if (H->left)
            H->left->color = !H->left->color;
        if (H->right)
            H->right->color = !H->right->color;
    }

    void transplant(node_type *u, node_type* &v) {
        if (u->parent == NULL || u == u->parent->left) {
            if (u->parent == NULL) {
                root = v;
            }
            else {
                u->parent->left = v;
            }
            if (v) {
                if (v != u->left) {
                    v->left = u->left;
                    v->left->parent = v;
                }
                v->right = u->right;
                if (v->right) {
                    v->right->parent = v;
                }
            }
        }
        else {
            u->parent->right = v;
        }
        if (v) {
            v->parent = u->parent;
        }
    }

    void deleteFixup(node_type *X) {
        if (X) {
            while (X != root && X->color == 0) {
                node_type *W = X->parent->right;
                if (W->color == 1) {
                    W->color = 0;
                    X->parent->color = 1;
                    W = X->parent->right;
                }
                if (W->left && W->left->color == 0 && W->right && W->right->color == 0) {
                    W->color = 1;
                    X->right->color = 1;
                    X = X->parent;
                }
                else {
                    if (W->right) {
                        if (W->right->color == 0) {
                            W->left->color = 0;
                            W->color = 1;
                            W = X->parent->right;
                        }
                        W->right->color = 0;
                    }
                    W->color = X->parent->color;
                    X->parent->color = 0;
                    X = root;
                }
            } 
            X->color = 0;
        }
    }
};
}
#endif