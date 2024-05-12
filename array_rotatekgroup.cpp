#include<bits/stdc++.h>

using namespace std;

void rotatekth_grp(int arr[],int k,int n){
    int narr[k];
    for(int i=0;i<k;i++){
        narr[i]=arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=n-k;i<n;i++){
        arr[i]=narr[i-(n-k)];
    }
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    rotatekth_grp(arr,6,n);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}