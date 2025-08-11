#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente = nullptr;
    Nodo* final = nullptr;
    void encolar(int v) {
        Nodo* n = new Nodo{v, nullptr};
        if (!frente) {
            frente = final = n;
        } else {
            final->siguiente = n;
            final = n;
        }
    }
    int desencolar() {
        int v = frente->valor;
        Nodo* tmp = frente;
        frente = frente->siguiente;
        if (!frente) final = nullptr;
        delete tmp;
        return v;
    }
    bool vacia() { return !frente; }
};

int main() {
    Cola c;
    c.encolar(1);
    c.encolar(2);
    c.encolar(3);
    while (!c.vacia())
        cout << c.desencolar() << ' ';
    cout << endl;
    return 0;
}
