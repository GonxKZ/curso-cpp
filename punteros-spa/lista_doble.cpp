#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* sig;
    Nodo* ant;
};

void insertarInicio(Nodo*& cabeza, int v) {
    Nodo* n = new Nodo{v, cabeza, nullptr};
    if (cabeza) cabeza->ant = n;
    cabeza = n;
}

void mostrar(Nodo* n) {
    while (n) {
        cout << n->valor << ' ';
        if (!n->sig) break;
        n = n->sig;
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;
    insertarInicio(lista, 1);
    insertarInicio(lista, 2);
    insertarInicio(lista, 3);
    mostrar(lista);
    while (lista) {
        Nodo* t = lista;
        lista = lista->sig;
        delete t;
    }
    return 0;
}
