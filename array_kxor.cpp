#include<bits/stdc++.h>

using namespace std;

int k_xors(vector<int>arr,int k){
    int n=arr.size();
    map<int,int>mpp;
    int xr=0,cnt=0;
    mpp[xr]++;
    for(int i=0;i<n;i++){
        xr=xr^arr[i];
        int x=xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
}

int main(){
    vector<int>arr={4,2,2,6,4};
    int ans=k_xors(arr,6);
    cout<<"Number of xors equal to k: "<<ans;

    return 0;
}