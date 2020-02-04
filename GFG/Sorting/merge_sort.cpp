#include<iostream>

using namespace std;

void merge(int arr[],int l,int mid,int h){
    int *tmp = new int[h-l+1];
    int in = 0;
    int l1 = l;
    int l2 = mid+1;
    while(l1<=mid && l2<=h){
        if(arr[l1]<=arr[l2])
            tmp[in++] = arr[l1++];
        else
            tmp[in++] = arr[l2++];
    }
    while(l1<=mid)
        tmp[in++] = arr[l1++];
    while(l2<=h)
        tmp[in++] = arr[l2++];
    for(int i=0;i<h-l+1;i++)
        arr[i+l] = tmp[i];
}

void merge_sort(int arr[],int l,int h){
    int mid = l+(h-l)/2;
    if(l<h){
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}