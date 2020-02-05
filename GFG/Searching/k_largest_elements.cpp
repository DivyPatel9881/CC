#include<bits/stdc++.h>

using namespace std;

void Swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}

void Heapify(int arr[],int in,int n){
    int l1 = 2*in+1;
    int l2 = 2*in+2;
    if(l1<n && l2<n){
        int largest = in;
        if(arr[largest] < arr[l1])
            largest = l1;
        if(arr[largest] < arr[l2])
            largest = l2;
        if(largest!=in){
            Swap(arr[largest], arr[in]);
            Heapify(arr,largest,n);
        }
    }
    else if(l1<n){
        int largest = in;
        if(arr[largest] < arr[l1])
            largest = l1;
        if(largest!=in)
            Swap(arr[largest], arr[in]);
    }
}

vector<int> k_largest_elements(int arr[],int n,int k){
    int l = (n-2)/2;
    vector<int> v;
    for(int i=l;i>=0;i--)
        Heapify(arr,i,n);
    for(int i=n-1;i>=n-k;i--){
        Swap(arr[i], arr[0]);
        v.push_back(arr[i]);
        Heapify(arr,0,i);
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    vector<int> v = k_largest_elements(arr,n,k);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}