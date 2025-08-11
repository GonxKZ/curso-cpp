#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

void insertar(Node*& r, int v) {
    if (!r) {
        r = new Node{v, nullptr, nullptr};
        return;
    }
    if (v < r->val)
        insertar(r->left, v);
    else
        insertar(r->right, v);
}

void inorder(Node* r) {
    if (!r) return;
    inorder(r->left);
    cout << r->val << ' ';
    inorder(r->right);
}

void liberar(Node* r) {
    if (!r) return;
    liberar(r->left);
    liberar(r->right);
    delete r;
}

int main() {
    Node* raiz = nullptr;
    insertar(raiz, 5);
    insertar(raiz, 2);
    insertar(raiz, 8);
    insertar(raiz, 1);
    inorder(raiz);
    cout << endl;
    liberar(raiz);
    return 0;
}
