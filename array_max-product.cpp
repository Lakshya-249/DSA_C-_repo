#include<bits/stdc++.h>

using namespace std;

int maxproduct(int arr[],int n){
    int pre=1,suff=1;
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        if(pre==0) pre=1;
        if(suff==0) suff=1;
        pre *= arr[i];
        suff *= arr[n-i-1];
        ans = max(ans,max(pre,suff)); 
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