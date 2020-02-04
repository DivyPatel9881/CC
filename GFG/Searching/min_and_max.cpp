#include<bits/stdc++.h>

using namespace std;

int min(int a,int b){
    return a<b?a:b;
}

int max(int a,int b){
    return a>b?a:b;
}

pair<int,int> min_and_max(int arr[],int n){
    int Min;
    int Max;
    int l;
    if(n%2==0){
        Min = min(arr[0], arr[1]);
        Max = max(arr[0], arr[1]);
        l = 2;
    }
    else{
        Min = arr[0];
        Max = arr[0];
        l=1;
    }
    for(int i=l;i<n-1;i++){
        Min = min(Min,min(arr[i],arr[i+1]));
        Max = max(Max,max(arr[i],arr[i+1]));
    }
    pair<int,int> p ;
    p.first = Max;
    p.second = Min;
    return p;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    pair<int,int> p = min_and_max(arr,n);
    cout<<p.first<<" "<<p.second<<endl;
    return 0;
}