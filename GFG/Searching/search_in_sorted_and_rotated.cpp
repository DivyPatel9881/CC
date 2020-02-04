#include<iostream>
using namespace std;

int search_in_sorted_and_rotated(int arr[],int l,int h,int k){
    int mid = l + (h-l)/2;
    if(h-l>=2){
        if(arr[mid]==k)
            return mid;
        else if(arr[mid]<arr[h]){
            if(arr[mid]>k)
                return search_in_sorted_and_rotated(arr,l,mid-1,k);
            else if(arr[mid]<k && arr[h]<k)
                return search_in_sorted_and_rotated(arr,l,mid-1,k);
            else
                return search_in_sorted_and_rotated(arr,mid+1,h,k);
        }
        else if(arr[mid]>arr[l]){
            if(arr[mid]<k)
                return search_in_sorted_and_rotated(arr,mid+1,h,k);
            else if(arr[mid]>k && arr[l]<=k)
                return search_in_sorted_and_rotated(arr,l,mid-1,k);
            else
                return search_in_sorted_and_rotated(arr,mid+1,h,k);
        }
    }
    if(arr[l]==k)
        return l;
    else if(arr[h]==k)
        return h;
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
    cout<<search_in_sorted_and_rotated(arr,0,n-1,k)<<endl;
    return 0;
}