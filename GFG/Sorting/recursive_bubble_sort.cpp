#include<iostream>

using namespace std;

void Swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

void recursive_bubble_sort(int arr[],int n){
    if(n>1){
        bool swapped = false;
        for(int i=0;i<n-1;i++)
            if(arr[i]>arr[i+1]){
                Swap(arr[i],arr[i+1]);
                swapped = true;
            }
        if(swapped){
            recursive_bubble_sort(arr, n-1);
        }
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    recursive_bubble_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}