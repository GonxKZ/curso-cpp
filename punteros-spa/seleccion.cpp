#include <iostream>
using namespace std;

void seleccion(int* arr, int n){
    for(int i=0;i<n-1;++i){
        int min=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[min]) min=j;
        }
        if(min!=i){
            int tmp=arr[i];
            arr[i]=arr[min];
            arr[min]=tmp;
        }
    }
}

int main(){
    int datos[5]={5,4,3,2,1};
    seleccion(datos,5);
    for(int i=0;i<5;++i) cout<<datos[i]<<' ';
    cout<<endl;
    return 0;
}
