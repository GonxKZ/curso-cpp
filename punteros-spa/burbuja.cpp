#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    int datos[5] = {5, 2, 4, 3, 1};
    bubbleSort(datos, 5);

    for (int i = 0; i < 5; ++i) {
        cout << datos[i] << ' ';
    }
    cout << endl;
    return 0;
}
