#include <iostream>
#include <vector>
using namespace std;

struct Heap {
    vector<int> a;
    void push(int v) {
        a.push_back(v);
        int i = a.size() - 1;
        while (i > 0 && a[(i-1)/2] < a[i]) {
            swap(a[(i-1)/2], a[i]);
            i = (i-1)/2;
        }
    }
    int pop() {
        int v = a[0];
        a[0] = a.back();
        a.pop_back();
        int i = 0;
        while (true) {
            int l = 2*i+1, r = 2*i+2, m = i;
            if (l < (int)a.size() && a[l] > a[m]) m = l;
            if (r < (int)a.size() && a[r] > a[m]) m = r;
            if (m == i) break;
            swap(a[i], a[m]);
            i = m;
        }
        return v;
    }
    bool empty() { return a.empty(); }
};

int main() {
    Heap h;
    h.push(3);
    h.push(1);
    h.push(5);
    while (!h.empty())
        cout << h.pop() << ' ';
    cout << endl;
    return 0;
}
