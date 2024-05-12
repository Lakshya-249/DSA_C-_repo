#include<bits/stdc++.h>

using namespace std;

int find_missing_num(int arr[],int n){
    int xor1=0,xor2=0;
    for(int i=0;i<n;i++){
        xor1=xor1^arr[i];
        xor2=xor2^(i+1);
    }
    xor2=xor2^arr[n-1];
    return xor1^xor2;
}

int main(){
    int arr[]={1,2,3,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=find_missing_num(arr,n);
    cout<<"Missing number: "<<ans;

    return 0;
}