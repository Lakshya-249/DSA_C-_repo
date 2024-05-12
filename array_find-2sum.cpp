#include<bits/stdc++.h>

using namespace std;

pair<int,int> find_2sum(int arr[],int n,int k){
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        if(mpp.find(k-arr[i])!=mpp.end()){
            return make_pair(mpp[k-arr[i]],i);
        }
        mpp[arr[i]]=i;
    }
    return make_pair(0,0);
}

int main(){
    int arr[]={1,2,5,8,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    pair<int,int> ans=find_2sum(arr,n,13);
    cout<<"Index of the sum of 2 numbers from array: "<<ans.first<<","<<ans.second;

    return 0;
}