#include<bits/stdc++.h>

using namespace std;

void rotatekth_grp(int arr[],int k,int n){
    reverse(arr,arr+k);
    reverse(arr+k,arr+n);
    reverse(arr,arr+n);
}

int main(){
    int arr[]={1,2,3,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    rotatekth_grp(arr,3,n);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    return 0;
}