#include<iostream>

using namespace std;

int lower(int arr[],int l,int h,int k){
    int mid = l+(h-l)/2;
    if(l<h){
        if(arr[mid]==k)
            return lower(arr,l,mid,k);
        else if(arr[mid]<k)
            return lower(arr,mid+1,h,k);
        else if(arr[mid]>k)
            return lower(arr,l,mid-1,k);
    }
    if(arr[l]==k)
        return l;
    return -1;
}

int higher(int arr[],int l,int h,int k){
    int mid = l+(h-l)/2;
    if(h-l>1){
        if(arr[mid]==k)
            return higher(arr,mid,h,k);
        else if(arr[mid]<k)
            return higher(arr,mid+1,h,k);
        else if(arr[mid]>k)
            return higher(arr,l,mid-1,k);
    }
    if(arr[h]==k)
        return h;
    else if(arr[l]==k)
        return l;
    return -1;
}

int count_occurences(int arr[],int n,int k){
    int l = lower(arr,0,n-1,k);
    int h = higher(arr,0,n-1,k);
    if(l==-1)
        return -1;
    else
        return h-l+1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    cout<<count_occurences(arr,n,k)<<endl;
    return 0;
}