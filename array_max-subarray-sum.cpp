#include<bits/stdc++.h>

using namespace std;

int find_maxsum(int arr[],int n){
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
        }
        if(sum<0) sum=0;
    }
    return maxi;
}

int main(){
    int arr[]={-1,-2,5,6,-3,2,-4,7,-1,-3,0,-5};
    int n=sizeof(arr)/sizeof(int);
    int ans=find_maxsum(arr,n);
    cout<<"Maximum sum of the an array: "<<ans;

    return 0;
}