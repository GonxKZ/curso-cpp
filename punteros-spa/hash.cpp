#include <iostream>
#include <vector>
using namespace std;

struct Hash {
    vector<vector<int>> tabla;
    Hash(int n) : tabla(n) {}
    int h(int v) { return v % tabla.size(); }
    void insertar(int v) { tabla[h(v)].push_back(v); }
    void mostrar() {
        for (size_t i = 0; i < tabla.size(); ++i) {
            cout << i << ':';
            for (int x : tabla[i]) cout << ' ' << x;
            cout << '\n';
        }
    }
};

int main() {
    Hash h(5);
    h.insertar(1);
    h.insertar(6);
    h.insertar(11);
    h.mostrar();
    return 0;
}
