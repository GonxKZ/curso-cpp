#include <iostream>
using namespace std;

int busquedaLineal(int* arr,int n,int clave){
    for(int i=0;i<n;++i){
        if(arr[i]==clave) return i;
    }
    return -1;
}

int main(){
    int datos[5]={3,1,4,2,5};
    int pos=busquedaLineal(datos,5,4);
    cout<<"Posicion:"<<pos<<endl;
    return 0;
}
