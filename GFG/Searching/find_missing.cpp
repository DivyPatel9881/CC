#include<iostream>
using namespace std;

int find_missing(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];
    return (n+1)*(n+2)/2 - sum;
}

int  main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<find_missing(arr,n)<<endl;
    return 0;
}