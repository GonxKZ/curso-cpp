#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izq;
    Nodo* der;
};

Nodo* crear(int v) { return new Nodo{v, nullptr, nullptr}; }

void preorden(Nodo* r) {
    if (!r) return;
    cout << r->valor << ' ';
    preorden(r->izq);
    preorden(r->der);
}

void liberar(Nodo* r) {
    if (!r) return;
    liberar(r->izq);
    liberar(r->der);
    delete r;
}

int main() {
    Nodo* raiz = crear(1);
    raiz->izq = crear(2);
    raiz->der = crear(3);
    raiz->izq->izq = crear(4);
    preorden(raiz);
    cout << endl;
    liberar(raiz);
    return 0;
}
