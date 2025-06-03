#include <iostream>
using namespace std;

struct Punto {
    int x;
    int y;
};

int main() {
    Punto p{4, 5};
    Punto* ptr = &p;

    cout << "Punto en (" << ptr->x << ", " << ptr->y << ")" << endl;
    cout << "Direccion de p: " << &p << endl;
    cout << "Direccion almacenada en ptr: " << ptr << endl;
    return 0;
}
