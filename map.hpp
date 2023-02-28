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

    int search(int value) {
        node *tree = root;
        int res = -1;

        if (tree) {
            while (tree)
            {
                if (value > tree->value) {
                    tree = tree->right;
                }
                else {
                    if (value == tree->value) {
                        res = value;
                        break ;
                    }
                    tree = tree->left;
                }
            }   
        }
        return res;
    }

    int remove(int value) {
        node *tree = root;
        while (tree)
        {
            if (value > tree->value) {
                tree = tree->right;
            }
            else {
                if (value == tree->value) {
                    node *u = tree;
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
                    delete_fixup(tree);
                    return 1;
                }
                tree = tree->left;
            }
        }
        return 0;
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
        S->color = 0;
        S->parent = P;
    }

    void leftRotate(node* S) {
        node *P = S->parent != NULL ? S->parent->parent : NULL;
        if (P) {
            if (P->right == S->parent) {
                P->right = S;
            }
            else {
                P->left = S;
            }
        }
        node *T = S->right;
        if (T) {
            T->parent = S->parent;
        }
        S->right = S->parent;
        S->right->parent = S;
        S->left->color = 1;
        S->right->color = 1;
        S->right->left = T;
        S->color = 0;
        S->parent = P;
    }

    void invertColor(node* H) {
        H->color = !H->color;
        if (H->left)
            H->left->color = !H->left->color;
        if (H->right)
            H->right->color = !H->right->color;
    }

    void transplant(node *u, node* &v) {
        if (u->parent == NULL) {
            root = v;
            root->right = u->right;
            root->left = u->left;
        }
        else if (u == u->parent->left) {
            u->parent->left = v;
            v->left = u->left;
            v->right = u->right;
        }
        else {
            u->parent->right = v;
        }
        v->parent = u->parent;
    }

    void delete_fixup(node *X) {
        while (X != root && X->color == 0) {
            node *W = X->parent->right;
            if (W->color == 1) {
                W->color = 0;
                X->parent->color = 1;
                W = X->parent->right;
            }
            if (W->left->color == 0 && W->right->color == 0) {
                W->color = 1;
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
}
#endif