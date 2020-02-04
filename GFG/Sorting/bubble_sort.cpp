#include <iostream>

using namespace std;

void Swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void bubble_sort(int arr[],int n){
    bool swapped = false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[i]>arr[j]){
                Swap(arr[i],arr[j]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}