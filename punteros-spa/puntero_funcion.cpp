#include <iostream>
using namespace std;

int sumar(int a, int b) { return a + b; }

int main() {
    // Declarar un puntero a funcion que tome dos int y devuelva int
    int (*pf)(int, int) = &sumar;
    int resultado = pf(2, 3); // llamar a traves del puntero

    cout << "Resultado de sumar(2,3): " << resultado << endl;
    cout << "Direccion de sumar: " << (void*)pf << endl;
    return 0;
}
