#include<iostream>
#include<cmath>
#define MIN -988888888

using namespace std;

void radix_sort(int arr[],int n){
    int Max = MIN;
    for(int i=0;i<n;i++)
        if(Max<arr[i])
            Max=arr[i];
    int num_digs = 0;
    while(Max){
        Max/=10;
        num_digs++;
    }
    for(int i=0;i<num_digs;i++){
        int *arr2 = new int[10];
        int **arr1 = new int *[10];
        for(int j=0;j<10;j++){
            arr1[j] = new int[n];
            arr2[j] = 0;
        }
        for(int j=0;j<n;j++){
            int num = arr[j];
            int dig = (num % (10*(i+1)))/pow(10,i);
            arr1[dig][arr2[dig]++] = arr[j];
        }
        int in = 0;
        for(int j=0;j<10;j++)
            for(int k=0;k<arr2[j];k++)
                arr[in++] = arr1[j][k];
    }
}

int main(){
    int n;
    cin>>n;
    int *arr = new int [n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    radix_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}