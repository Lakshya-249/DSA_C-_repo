#include<bits/stdc++.h>

using namespace std;

pair<int,int> find_2sum(int arr[],int n,int k){
    int i=0,j=n-1;
    sort(arr,arr+n);
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum==k){
            return make_pair(i,j);
        }else if(sum<k){
            i++;
        }else j++;
    }
    return make_pair(0,0);
}

int main(){
    int arr[]={1,2,5,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    pair<int,int> ans=find_2sum(arr,n,13);
    cout<<"Index of the sum of 2 numbers from array: "<<ans.first<<","<<ans.second;

    return 0;
}