#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <memory>
#include "Node.hpp"

template<class Key, class T, class Allocator = std::allocator<T> >
class Tree
{
public:
	typedef Key	key_type;
    typedef T	value_type;
    typedef Allocator 						allocator_type;
    typedef Node< key_type , value_type, allocator_type> node_type;
    typename Allocator::template rebind<node_type>::other rebind_allocator;

    Tree(): root(NULL) {}

    ~Tree() {
        clear();
    }


    void insert(Key key, T value) {
        if (root) {
            while (root) {
                if (root->key == key) {
                    return ;
                }
                if (key < root->key) {
                    if (root->left) {
                        root = root->left;
                    }
                    else {
                        root->left = newNode(key, value, 1, root);
                        rebalance(root);
                        root->color = 0;
                        break ;
                    }
                }
                else {
                    if (root->right) {
                        root = root->right;
                    }
                    else {
                        root->right = newNode(key, value, 1, root);
                        rebalance(root);
                        root->color = 0;
                        _size++;
                        break ;
                    }
                }
            }
        }
        else {
            root = newNode(key, value, 0, root);
        }
    }

    void clear(void) {
        delete_all(root);
        root = NULL;
    }


    node_type *search(Key key) {
        node_type *tree = root;
        node_type *res = NULL;

        if (tree) {
            while (tree)
            {
                if (key > tree->key) {
                    tree = tree->right;
                }
                else {
                    if (key == tree->key) {
                        res = tree;
                        break ;
                    }
                    tree = tree->left;
                }
            }   
        }
        return res;
    }

    int remove(node_type *tree) {
        if (tree) {
            node_type *u = tree;
            if (tree->parent == NULL || tree->parent->left == u) {
                tree = tree->left;
                if (tree->right) {
                    while (tree->right) {
                        tree = tree->right;
                    }
                    tree->parent->right = NULL;
                }
                else {
                    tree->parent->left = NULL;
                }
            }
            else {
                tree = tree->right;
            }
            transplant(u, tree);
            deleteFixup(tree);
            rebind_allocator.deallocate(u, 1);
            _size--;
            return 1;
        }
        return 0;
    }

private:
    node_type* root;
    size_t  _size;
    allocator_type _allocator;

    void delete_all (node_type *R) {
        if (R) {
            if (R->left) {
                delete_all(R->left);
            }
            else if (R->right) {
                delete_all(R->right);
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
                rebind_allocator.deallocate(R, 1);
                delete_all(P);
            }
        }
    }

    node_type* newNode(Key key, T value, int color, node_type *parent) {
        node_type* var = rebind_allocator.allocate(1);
        var->left = NULL;
        var->right = NULL;
        var->key = key;
        var->value = value;
        var->color = color;
        var->parent = parent;
        return var;
    }

    node_type* minNode(void) {
        node_type *min = root;
        
        while (min->left)
        {
            min = min->left;
        }
        return min;
    }

    node_type* maxNode(void) {
        node_type *max = root;
        
        while (max->right)
        {
            max = max->right;
        }
        return max;
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
            v->left = u->left;
            if (v->left) {
                v->left->parent = v;
            }
            v->right = u->right;
            if (v->right) {
                v->right->parent = v;
            }
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void deleteFixup(node_type *X) {
        while (X != root && X->color == 0) {
            node_type *W = X->parent->right;
            if (W->color == 1) {
                W->color = 0;
                X->parent->color = 1;
                W = X->parent->right;
            }
            if (W->left->color == 0 && W->right->color == 0) {
                W->color = 1;
                X->right->color = 1;
                X = X->parent;
            }
            else { 
                if (W->right->color == 0) {
                    W->left->color = 0;
                    W->color = 1;
                    rightRotate(W);
                    W = X->parent->right;
                }
                W->color = X->parent->color;
                X->parent->color = 0;
                W->right->color = 0;
                leftRotate(X->parent);
                X = root;
            }
        } 
        X->color = 0;
    }
};
#endif