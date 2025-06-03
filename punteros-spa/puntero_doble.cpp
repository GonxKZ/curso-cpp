#include <iostream>
using namespace std;

int main() {
    int valor = 10;
    int* ptr = &valor;   // puntero simple
    int** dptr = &ptr;   // puntero doble

    cout << "Valor: " << valor << endl;
    cout << "Direccion de valor: " << &valor << endl;
    cout << "Direccion almacenada en ptr: " << ptr << endl;
    cout << "Direccion almacenada en dptr: " << dptr << endl;
    cout << "Valor al que apunta dptr: " << **dptr << endl;
    return 0;
}
