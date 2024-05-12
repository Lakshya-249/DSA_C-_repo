#include<bits/stdc++.h>

using namespace std;

int longest_subarray_sum(int arr[],int n,int k){
    int i=0,j=0;
    int sum=0;
    int maxlen=0;
    while(i<=j && j<n){
        sum+=arr[j];
        while(sum>k){
            sum = sum-arr[i];
            i++;
        }
        if(sum==k) maxlen=max(maxlen,j-i+1);
        j++;
    }
    return maxlen;
}

int main(){
    int arr[]={2,5,3,7,8,11,9,10,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=longest_subarray_sum(arr,n,35);
    cout<<"Maximum length of the subarray: "<<ans;

    return 0;
}