#include<bits/stdc++.h>

using namespace std;

int num_of_subarrays(int arr[],int n,int k){
    map<int,int>mpp;
    int sum=0,cnt=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            cnt++;
        }
        if(mpp.find(sum-k)!=mpp.end()){
            cnt+=mpp[sum-k];
        }
        mpp[sum]++;
        
    }
    return cnt;
}

int main(){
    int arr[]={1,2,3,-3,1,1,1,4,2,-3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=num_of_subarrays(arr,n,4);
    cout<<"Total number of subarrays of sum k: "<<ans;

    return 0;
}