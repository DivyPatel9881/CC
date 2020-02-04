#include<iostream>

using namespace std;

void insertion_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        int j;
        int t = arr[i];
        for(j=i-1;j>=0;j--){
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
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}