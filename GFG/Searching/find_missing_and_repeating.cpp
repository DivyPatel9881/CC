#include<bits/stdc++.h>

using namespace std;

pair<int,int> find_missing_and_repeating(int arr[],int n){
    map<int,bool> m;
    pair<int,int> p;
    int sum = 0;
    for(int i=0;i<n;i++){
        if(!m[arr[i]]){
            sum += arr[i];
            m[arr[i]] = true;
        }
        else
            p.first = arr[i];
    }
    p.second = n*(n+1)/2 - sum;
    return p;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    pair<int,int> p  = find_missing_and_repeating(arr,n);
    cout<<p.first<<" "<<p.second<<endl;;
    return 0;
}