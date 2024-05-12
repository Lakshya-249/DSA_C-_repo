#include<bits/stdc++.h>

using namespace std;

void sort012s(int arr[],int n){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }
    for(int i=0;i<mpp[0];i++) arr[i]=0;
    for(int i=mpp[0];i<mpp[0]+mpp[1];i++) arr[i]=1;
    for(int i=mpp[0]+mpp[1];i<n;i++) arr[i]=2;
}

int main(){
    int arr[]={1,0,2,1,1,0,0,1,2,2,2,0,1,1,0,2,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort012s(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}