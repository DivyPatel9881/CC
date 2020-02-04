#include<iostream>

using namespace std;

void Swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

int Partition(int arr[],int l,int h){
    int v = arr[h];
    int p = l;
    for(int i=l;i<h;i++){
        if(arr[i]<v)
            Swap(arr[i], arr[p++]);
    }
    Swap(arr[p], arr[h]);
    return p;
}

void quick_sort(int arr[],int l,int h){
    if(l<h){
        int p = Partition(arr,l,h);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,h);
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}