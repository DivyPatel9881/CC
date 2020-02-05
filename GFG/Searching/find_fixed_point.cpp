#include<iostream>

using namespace std;

int find_fixed_point(int arr[],int l,int h){
    int mid = l+(h-l)/2;
    if(l<=h){
        if(arr[mid]==mid)
            return mid;
        else if(arr[mid]<mid)
            return find_fixed_point(arr,mid+1,h);
        else
            return find_fixed_point(arr,l,mid-1);
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<find_fixed_point(arr,0,n-1)<<endl;
    return 0;
}