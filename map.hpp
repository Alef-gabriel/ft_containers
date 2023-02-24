#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <cstdlib>

namespace ft {

struct node {
    int   value;
    node* right;
    node* left;
    int color;
    node* parent;
};

class map
{
public:
    map(): root(NULL) {}
    ~map(){}
    void rebalance(node* &H) {
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


    void insert(int value) {
        if (root) {
            while (root) {
                if (root->value == value) {
                    return ;
                }
                if (value < root->value) {
                    if (root->left) {
                        root = root->left;
                    }
                    else {
                        root->left = createNodo(value, 1, root);
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
                        root->right = createNodo(value, 1, root);
                        rebalance(root);
                        root->color = 0;
                        break ;
                    }
                }
            }
        }
        else {
            root = createNodo(value, 0, root);
        }
    }

    node *search(node *tree, int value) {
        if (tree) {
            if (value > tree->value) {
                tree = tree->left;
            }
            else {
                if (value == tree->value) {
                    return tree;
                }
                tree = tree->right;
            }
            search(tree, value);
        }
        return NULL;
    }

private:
    node* root;

    node* createNodo(int value, int color, node *parent) {
        node* var = (node *)malloc(sizeof(node));
        var->left = NULL;
        var->right = NULL;
        var->value = value;
        var->color = color;
        var->parent = parent;
        return var;
    }

    void rightRotate(node* &S) {
        node *P = S->parent->parent != NULL ? S->parent->parent : NULL;
        if (P) {
            if (P->right == S->parent) {
                P->right = S;
            }
            else {
                P->left = S;
            }
        }
        node *T = S->left;
        if (T) {
            T->parent = S->parent;
        }
        S->left = S->parent;
        S->left->right = T;
        S->left->parent = S;
        S->left->color = 1;
        S->right->color = 1;
        S->parent = P;
    }

    void leftRotate(node* &S) {
        node *P = S->parent->parent != NULL ? S->parent->parent : NULL;
        if (P) {
            if (P->right == S->parent) {
                P->right = S;
            }
            else {
                P->left = S;
            }
        }
        node *T = S->left;
        if (T) {
            T->parent = S->parent;
        }
        S->left = S->parent;
        S->left->right = T;
        S->left->parent = S;
        S->left->color = 1;
        S->right->color = 1;
        S->parent = P;
    }

    void invertColor(node* H) {
        H->color = !H->color;
        if (H->left)
            H->left->color = !H->left->color;
        if (H->right)
            H->right->color = !H->right->color;
    }
};
}
#endif