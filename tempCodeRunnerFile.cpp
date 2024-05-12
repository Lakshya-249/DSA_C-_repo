#include<bits/stdc++.h>

using namespace std;

void subsets(int arr[],vector<vector<int>>&ans,int ind,int n,vector<int>&ds){
    ans.push_back(ds);
    for(int i=ind;i<n;i++){
        ds.push_back(arr[i]);
        subsets(arr,ans,i+1,n,ds);
        ds.pop_back();
    }
}

vector<vector<int>> find(int arr[],int n){
    vector<int>ds;
    vector<vector<int>>ans;
    subsets(arr,ans,0,n,ds);
    return ans;
}

int main(){
    int arr[]={1,2,3};
    int n=sizeof(arr)/sizeof(int);
    vector<vector<int>>ans=find(arr,n);
    for(auto itr: ans){
        for(auto it: itr) cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}