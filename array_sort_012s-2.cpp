#include<bits/stdc++.h>

using namespace std;

int sort012s(int arr[],int n){
    int i=0,j=0,k=n-1;
    while(j<k){
        if(arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }else if(arr[j]==2){
            swap(arr[j],arr[k]);
            k--;
        }else{
            j++;
        }
    }
}

int main(){
    int arr[]={1,0,2,1,1,0,0,1,2,2,2,0,1,1,0,2,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort012s(arr,n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}