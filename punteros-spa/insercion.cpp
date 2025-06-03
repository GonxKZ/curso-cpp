#include <iostream>
using namespace std;

void insercion(int* arr,int n){
    for(int i=1;i<n;++i){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=key;
    }
}

int main(){
    int datos[5]={5,1,4,2,3};
    insercion(datos,5);
    for(int i=0;i<5;++i) cout<<datos[i]<<' ';
    cout<<endl;
    return 0;
}
