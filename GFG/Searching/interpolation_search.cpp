#include<iostream>
using namespace std;

int interpolation_search(int arr[],int n,int k){
    int l = 0;
    int h = n-1;
    while(l<h){
        int p = (h - l) * (k - arr[l]) / (arr[h] - arr[l]) + l;
        if(arr[p]==k)
            return p;
        else if(arr[p]<k)
            l = p+1;
        else
            h = p-1;
    }
    if(arr[l]==k)
        return l;
    return -1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<interpolation_search(arr,n,k)<<endl;
    return 0;
}