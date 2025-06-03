#include <iostream>
using namespace std;

int main() {
    int valor = 5;
    int* ptr = &valor;

    cout << "Valor: " << valor << endl;
    cout << "Direccion de valor: " << &valor << endl;
    cout << "Direccion almacenada en ptr: " << ptr << endl;
    cout << "Valor al que apunta ptr: " << *ptr << endl;
    return 0;
}
