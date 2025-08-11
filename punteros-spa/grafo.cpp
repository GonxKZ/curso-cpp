#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> g = {{1,2},{2},{0},{}};
    for (size_t i = 0; i < g.size(); ++i) {
        cout << "Vertice " << i << ':';
        for (int v : g[i]) cout << ' ' << v;
        cout << '\n';
    }
    return 0;
}
