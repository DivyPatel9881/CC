#include<iostream>
using namespace std;

int min(int a,int b){
    return a<b?a:b;
}

int max(int a,int b){
    return a>b?a:b;
}

float median(int arr1[],int l1,int h1,int arr2[],int l2,int h2){
    int mid1 = l1 + (h1-l1)/2;
    int mid2 = l2 + (h2-l2)/2;
    if(h1-l1>1 || h2-l2>1){
        if(arr1[mid1] < arr2[mid2])
            return median(arr1,mid1,h1,arr2,l2,mid2);
        else if(arr1[mid1]>arr2[mid2])
            return median(arr1,l1,mid1,arr2,mid2,h2);
        else
            return median(arr1,mid1,h1,arr2,mid2,h2);
    }
    return (min(arr1[h1],arr2[h2]) + max(arr1[l1], arr2[l2]))/2.0;
}

int main(){
    int n;
    cin>>n;
    int *arr1 = new int [n];
    int *arr2 = new int [n];
    for(int i=0;i<n;i++)
        cin>>arr1[i];
    for(int i=0;i<n;i++)
        cin>>arr2[i];
    cout<<median(arr1,0,n-1,arr2,0,n-1)<<endl;
    return 0;
}