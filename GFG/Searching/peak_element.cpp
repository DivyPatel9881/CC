#include<iostream>

using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int peak_element(int arr[],int l, int h){
    int mid = l + (h-l)/2;
    if(h-l>=2){
        if(arr[mid-1]<=arr[mid] && arr[mid]<=arr[mid+1])
            return peak_element(arr,mid+1,h);
        else if(arr[mid-1]>=arr[mid] && arr[mid]>=arr[mid+1])
            return peak_element(arr,l,mid-1);
        else if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1])
            return arr[mid];
    }
    return max(arr[l],max(arr[mid], arr[h]));
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<peak_element(arr,0,n-1)<<endl;
    return 0;
}