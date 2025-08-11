#include <iostream>
using namespace std;

int main() {
    int filas = 2, cols = 3;
    int** matriz = new int*[filas];

    for (int i = 0; i < filas; ++i) {
        matriz[i] = new int[cols];
    }

    int contador = 1;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < cols; ++j) {
            matriz[i][j] = contador++;
            cout << matriz[i][j] << ' ';
        }
        cout << endl;
    }

    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}
