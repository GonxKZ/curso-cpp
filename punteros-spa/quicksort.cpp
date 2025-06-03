#include <iostream>
using namespace std;

int partition(int* arr,int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;++j){
        if(arr[j]<pivot){
            ++i;
            int t=arr[i];arr[i]=arr[j];arr[j]=t;
        }
    }
    int t=arr[i+1];arr[i+1]=arr[r];arr[r]=t;
    return i+1;
}

void quickSort(int* arr,int l,int r){
    if(l<r){
        int p=partition(arr,l,r);
        quickSort(arr,l,p-1);
        quickSort(arr,p+1,r);
    }
}

int main(){
    int datos[6]={3,6,1,5,2,4};
    quickSort(datos,0,5);
    for(int i=0;i<6;++i) cout<<datos[i]<<' ';
    cout<<endl;
    return 0;
}
