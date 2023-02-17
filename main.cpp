#include <iostream>
#include <cstdlib>

struct node {
    int   value;
    node* right;
    node* left;
    int color;
    node* parent;
};

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
    node *P = S->parent != NULL ? S->parent->right : NULL;
    if (P) {
        S->parent->right = S->right;
    }
    node *t = S->parent;
    P = S->right;
    S->right->right = S;
    S->right->parent = S->parent;
    S = P;
    S->color = 0;
    S->right->color = 1;
    S->right->parent = S;
    S->right->right = NULL;
    S->parent = t;
}

void leftRotate(node* &S) {
    node *P = S->parent != NULL ? S->parent->left : NULL;
    if (P) {
        S->parent->left = S->left;
    }
    node *t = S->parent;
    P = S->left;
    S->left->right = S;
    S->left->parent = S->parent;
    S = P;
    S->color = 0;
    S->right->color = 1;
    S->right->parent = S;
    S->right->left = NULL;
    S->parent = t;
}

void invertColor(node* H) {
    H->color = !H->color;
    if (H->left)
        H->left->color = !H->left->color;
    if (H->right)
        H->right->color = !H->right->color;
}

node* rebalance(node* &H) {

    node* S = H;

    while (H != NULL)
    {
        if (H->left != NULL && H->left->color == 1 && H->left->left && H->left->left->color == 1 && H->right && H->right->color == 1) {
            invertColor(H);
        }
        else if (H->right != NULL && H->color == 1 && H->right->color == 1) {
            rightRotate(H->parent);
            if (!H->parent) {
                S = H;
            }
        }
        else if (H->left != NULL && H->left->color == 1 && H->color == 1) {
            leftRotate(H->parent);
            if (!H->parent) {
                S = H;
            }
        }
        if (H->left) {
            H = H->left;
        }
        else {
            H = H->right;
        }
    }
    return S;
}


void insert(node* &data, node *parent, int value) {
    if (data) {
        if (data->value == value) {
            return ;
        }
        if (value > data->value) {
            insert(data->right, data, value);
        }
        else {
            insert(data->left, data, value);
        }
    }
    else {
        data = createNodo(value, 1, parent);
    }
}

node *newNo(node *H, int value) {
    node *tree = H;

    insert(tree, NULL, value);
    tree->color = 0;
    tree = rebalance(tree);
    tree->color = 0;
    return tree;
}

int main() {
    node *tree = NULL;

    tree = newNo(tree, 100);
    tree = newNo(tree, 50);
    tree = newNo(tree, 40);
    tree = newNo(tree, 20);
    tree = newNo(tree, 10);
    tree = newNo(tree, 8);
    tree = newNo(tree, 5);

    // insert(tree, NULL, 100);
    // insert(tree, NULL, 50);
    // insert(tree, NULL, 40);
    // insert(tree, NULL, 20);
    // insert(tree, NULL, 10);
    return 0;
}