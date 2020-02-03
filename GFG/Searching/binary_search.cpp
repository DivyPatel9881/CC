#include<iostream>
using namespace std;

int binary_search(int arr[],int l,int h,int k){
    int mid = l + (h-l)/2;
    if(l<=h){
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<k)
            return binary_search(arr, mid+1, h, k);
        else
            return binary_search(arr, l, mid-1, k);
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<binary_search(arr,0,n-1,k)<<endl;
    return 0;
}