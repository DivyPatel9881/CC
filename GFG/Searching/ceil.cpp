#include<iostream>

using namespace std;

int ceil(int arr[],int l,int h,int k){
    int mid = l + (h-l)/2;
    if(l<h){
        if(arr[mid]==k)
            return k;
        else if(arr[mid]<k)
            return ceil(arr,mid+1,h,k);
        else
            return ceil(arr,l,mid,k);
    }
    if(arr[l]>=k)
        return arr[l];
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
    cout<<ceil(arr,0,n-1,k)<<endl;
    return 0;
}