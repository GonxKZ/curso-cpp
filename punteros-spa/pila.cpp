#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

void push(Nodo*& cima, int v) {
    cima = new Nodo{v, cima};
}

int pop(Nodo*& cima) {
    int v = cima->valor;
    Nodo* tmp = cima;
    cima = cima->siguiente;
    delete tmp;
    return v;
}

int main() {
    Nodo* pila = nullptr;
    push(pila, 1);
    push(pila, 2);
    push(pila, 3);
    cout << pop(pila) << ' ';
    cout << pop(pila) << ' ';
    cout << pop(pila) << endl;
    return 0;
}
