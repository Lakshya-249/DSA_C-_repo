#include<bits/stdc++.h>

using namespace std;

int maxproduct(int arr[],int n){
    int pre=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        pre*=arr[i];
        ans=max(ans,pre);
        if(pre<0 || pre==0) pre=1; 
    }
    return ans;
}

int main(){
    int arr[]={2,3,-1,4,5,0,-2,4,3,2,0,2,-1,6,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=maxproduct(arr,n);
    cout<<"Maximum product of the given array: "<<ans;

    return 0;
}