#include<bits/stdc++.h>

using namespace std;

pair <int,int> find_pair_with_diff(int arr[],int n,int k){
    int l = 0;
    int r = 1;
    pair<int,int> p;
    p.first = -1;
    p.second = -1;
    while(r<n){
        if(l==r)
            r++;
        else{
            int diff = arr[r] - arr[l];
            if(diff==k){
                p.first = arr[l];
                p.second = arr[r];
                break;
            }
            else if(diff>k)
                l++;
            else
                r++;
        }
    }
    return p;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    pair<int,int> p = find_pair_with_diff(arr,n,k);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}