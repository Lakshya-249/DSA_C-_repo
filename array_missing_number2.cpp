#include<bits/stdc++.h>

using namespace std;

int find_missing_num(int arr[],int n){
    int sum=(arr[n-1]*(arr[n-1]+1))/2;
    int nsum=0;
    for(int i=0;i<n;i++){
        nsum+=arr[i];
    }
    return sum-nsum;
}

int main(){
    int arr[]={1,2,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=find_missing_num(arr,n);
    cout<<"Missing number: "<<ans;

    return 0;
}