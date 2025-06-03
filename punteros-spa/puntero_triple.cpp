#include <iostream>
using namespace std;

int main() {
    int valor = 20;
    int* ptr = &valor;     // puntero simple
    int** dptr = &ptr;     // puntero doble
    int*** tptr = &dptr;   // puntero triple

    cout << "Valor: " << valor << endl;
    cout << "Direccion de valor: " << &valor << endl;
    cout << "Direccion almacenada en ptr: " << ptr << endl;
    cout << "Direccion almacenada en dptr: " << dptr << endl;
    cout << "Direccion almacenada en tptr: " << tptr << endl;
    cout << "Valor al que apunta tptr: " << ***tptr << endl;
    return 0;
}
