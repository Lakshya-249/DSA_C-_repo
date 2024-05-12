#include<bits/stdc++.h>

using namespace std;

vector<int> find_leader(int arr[],int n){
    int maxi=INT_MIN;
    vector<int>ans;
    for(int i=n-1;i>=0;i--){
        if(maxi<arr[i]){
            maxi=arr[i];
            ans.push_back(maxi);
        }
    }
    return ans;
}

int main(){
    int arr[]={10,22,12,3,0,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>ans=find_leader(arr,n);
    for(auto itr:ans) cout<<itr<<" ";

    return 0;
}