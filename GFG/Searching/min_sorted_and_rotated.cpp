#include<iostream>

using namespace std;

int min(int a,int b){
    return a<b?a:b;
}

int min_sorted_and_rotated(int arr[],int l,int h){
    int mid = l+(h-l)/2;
    if(h-l>=2){
        if(arr[l]<=arr[mid]){
            if(arr[h]>=arr[mid])
                return min_sorted_and_rotated(arr,l,mid-1);
            else if(arr[h]<=arr[mid])
                return min_sorted_and_rotated(arr,mid+1,h);
        }
        else if(arr[h]>=arr[mid])
            return min_sorted_and_rotated(arr,l,mid);
    }
    return min(arr[l], arr[h]);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<min_sorted_and_rotated(arr,0,n-1)<<endl;
    return 0;
}