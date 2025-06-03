#include <iostream>
using namespace std;

int busquedaBinaria(int* arr,int n,int clave){
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(arr[m]==clave) return m;
        if(arr[m]<clave) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(){
    int datos[5]={1,2,3,4,5};
    int pos=busquedaBinaria(datos,5,4);
    cout<<"Posicion:"<<pos<<endl;
    return 0;
}
