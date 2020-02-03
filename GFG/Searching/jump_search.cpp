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

int jump_search(int arr[], int n,int k, int steps){
    int flag = 0;
    int i;
    for(i=steps-1;;i+=steps){
        if(i>n){
            flag = 1;
            break;
        }
        if(arr[i]==k)
            return i;
        else if(arr[i]>k)
            return binary_search(arr, i-steps+1, i, k);
    }
    if(flag==1)
        return binary_search(arr, i-steps+1, n-1, k);
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
    int steps;
    cin>>steps;
    cout<<jump_search(arr,n,k,steps)<<endl;
    return 0;
}