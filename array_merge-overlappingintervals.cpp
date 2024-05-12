#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> merge_overlapping_interval(vector<vector<int>>arr){
    int n=arr.size();
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        if(!ans.empty() && end<=ans.back()[1]) continue;
        for(int j=i+1;j<n;j++){
            if(arr[j][0]<=end){
                end=max(end,arr[j][1]);
            }else break;
        }
        ans.push_back({start,end});
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={
        {1,3},
        {2,6},
        {8,9},
        {9,11},
        {8,10},
        {2,4},
        {15,18},
        {16,17}
    };
    vector<vector<int>>ans=merge_overlapping_interval(arr);
    for(auto it:ans){
        for(auto itr: it)cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}