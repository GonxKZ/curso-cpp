#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
};

void insertar(Nodo*& cabeza, int v) {
    Nodo* nuevo = new Nodo{v, cabeza};
    cabeza = nuevo;
}

void mostrar(Nodo* cabeza) {
    while (cabeza) {
        cout << cabeza->valor << " ";
        cabeza = cabeza->siguiente;
    }
    cout << endl;
}

int main() {
    Nodo* lista = nullptr;
    insertar(lista, 3);
    insertar(lista, 2);
    insertar(lista, 1);
    mostrar(lista);

    while (lista) { // liberar memoria
        Nodo* tmp = lista;
        lista = lista->siguiente;
        delete tmp;
    }
    return 0;
}
