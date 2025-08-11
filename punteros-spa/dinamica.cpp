#include <iostream>
using namespace std;

int main() {
    // Reservar memoria dinamicamente para un arreglo de 3 enteros
    int* datos = new int[3];
    datos[0] = 1;
    datos[1] = 2;
    datos[2] = 3;

    for (int i = 0; i < 3; ++i) {
        cout << "Elemento " << i << ": " << datos[i] << " en " << &datos[i] << endl;
    }

    delete[] datos; // liberar la memoria
    return 0;
}
