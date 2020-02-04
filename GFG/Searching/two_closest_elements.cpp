#include<bits/stdc++.h>
#define MAX 957656532
using namespace std;

int abs(int a){
    return a<0?-a:a;
}
pair<int,int> two_closest_elements(int arr[],int n){
    pair<int,int> p;
    int l = 0;
    int h = n-1;
    int Min = MAX;
    while(l<h){
        int diff = arr[l]+arr[h];
        int abs_diff = abs(diff);
        if(abs_diff<Min){
            Min = abs_diff;
            p.first = arr[l];
            p.second = arr[h];
        }
        if(diff==0)
            break;
        else if(diff<0)
            l++;
        else
            h--;
    }
    return p;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr, arr+n);
    pair<int,int> p = two_closest_elements(arr,n);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}