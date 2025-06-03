#include <iostream>
using namespace std;

int main() {
    int numeros[3] = {1,2,3};
    int* p = numeros; // apunta al primer elemento

    for(int i = 0; i < 3; ++i) {
        cout << "Valor " << *(p+i) << " en direccion " << (p+i) << endl;
    }
    return 0;
}
