#include<bits/stdc++.h>
#define MAX 988888888

using namespace std;

pair<int,int> smallest_and_second_smallest(int arr[],int n){
    int Min1 = MAX;
    int Min2 = MAX;
    for(int i=0;i<n;i++){
        if(Min1>arr[i]){
            Min2 = Min1;
            Min1 = arr[i];
        }
        else if(Min2>arr[i])
            Min2 = arr[i];
    }
    pair<int,int> p;
    p.first = Min1;
    p.second = Min2;
    return p;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    pair<int,int> p = smallest_and_second_smallest(arr,n);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}