#include<iostream>

using namespace std;

void recursive_insertion_sort(int arr[],int n){
    if(n>1){
        recursive_insertion_sort(arr, n-1);
        int t = arr[n-1];
        int j;
        for(j=n-2;j>=0;j--){
            if(arr[j]<t)
                break;
            else
                arr[j+1] = arr[j];
        }
        arr[j+1] = t;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    recursive_insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
