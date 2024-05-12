#include<bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int>&arr,int target){
    vector<int>ans;
    unordered_map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        if(mpp.find(target-arr[i])!=mpp.end()){
            ans.push_back(mpp[target-arr[i]]);
            ans.push_back(i);
            return ans;
        }
        mpp[arr[i]]=i;
    }
    return ans;
}

int main(){
    vector<int>ans,arr={2,7,1,8,9};
    ans=solution(arr,16);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}