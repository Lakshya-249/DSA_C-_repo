#include<bits/stdc++.h>
#include<vector>
using namespace std;

void recur(vector<int>&arr,vector<int>&vec,int i,int n,int s){
    if(s<0 || i==n) return;
    if (s==0){
        for (auto it:vec) cout<<it<<" ";
        cout<<endl;
        return;
    }
    vec.push_back(arr[i]);
    s-=arr[i];
    recur(arr,vec,i,n,s);
    vec.pop_back();
    s+=arr[i];
    recur(arr,vec,i+1,n,s);
}

void recur_(vector<int>&arr,vector<int>&vec,int s){
    recur(arr,vec,0,arr.size(),s);
}

int main(){
    vector<int>arr,vec;
    arr={4,5,7,1};
    recur_(arr,vec,20);
    return 0;
}