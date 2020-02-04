#include<iostream>
#include<cmath>

using namespace std;

void Swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

void shell_sort(int arr[],int n){
    for(int i=ceil(n/2.0);;i=ceil(i/2.0)){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+i])
                Swap(arr[j], arr[j+i]);
        }
        if(i==1)
            break;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    shell_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}