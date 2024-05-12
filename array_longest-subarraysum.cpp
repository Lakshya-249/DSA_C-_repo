#include<bits/stdc++.h>

using namespace std;

int longest_subarray_sum(int arr[],int n,int k){
    map<int,int>mpp;
    int sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        if(mpp.find(sum-k)!=mpp.end()){
            maxlen=max(maxlen,i-mpp[sum-k]);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
    }
    return maxlen;
}

int main(){
    int arr[]={2,5,3,7,8,11,9,10,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=longest_subarray_sum(arr,n,17);
    cout<<"Maximum length of the subarray: "<<ans;

    return 0;
}