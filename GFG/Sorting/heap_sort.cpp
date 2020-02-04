#include<iostream>
using namespace std;

void Swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

void Heapify(int arr[],int n,int in){
    int l = 2*in+1;
    int r = 2*in+2;
    if(l<n && r<n){
        int largest = in;
        if(arr[largest]<arr[l])
            largest = l;
        if(arr[largest]<arr[r])
            largest = r;
        if(largest!=in){
            Swap(arr[largest], arr[in]);
            Heapify(arr,n,largest);
        }
    }
    else if(l<n){
        int largest = in;
        if(arr[largest]<arr[l])
            largest = l;
        if(largest!=in)
            Swap(arr[largest], arr[in]);
    }
}

void heap_sort(int arr[],int n){
    int l = (n-2)/2;
    for(int i=l;i>=0;i--)
        Heapify(arr,n,i);
    for(int i=n-1;i>=1;i--){
        Swap(arr[i],arr[0]);
        Heapify(arr,i,0);
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    heap_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}