#include<bits/stdc++.h>

using namespace std;

vector<int> elements_more_than_nbyk(int arr[],int n,int k){
    vector<int> v;
    set<int> s;
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
        s.insert(arr[i]);
    }
    int nbyk = n/k;
    set<int>::iterator it;
    for(it = s.begin();it!=s.end();it++)
        if(m[*it]>nbyk)
            v.push_back(*it);
    return v;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    vector<int> v = elements_more_than_nbyk(arr,n,k);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}