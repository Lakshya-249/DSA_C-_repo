#include<bits/stdc++.h>

using namespace std;

int find_missing_num(int arr[],int n){
    bool mpp[arr[n-1]];
    for(int i=0;i<arr[n-1];i++){
        mpp[arr[i]]=true;
    }
    for(int i=1;i<=arr[n-1];i++){
        if(!mpp[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,4,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=find_missing_num(arr,n);
    cout<<"Missing number: "<<ans;

    return 0;
}