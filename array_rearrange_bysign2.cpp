#include<bits/stdc++.h>

using namespace std;

vector<int> rearrange_array(vector<int>arr){
    vector<int>pos,neg;
    int n=arr.size();
    for(auto it:arr){
        if(it<0)neg.push_back(it);
        else pos.push_back(it);
    }
    vector<int>ans(n,0);
    for(int i=0;i<n/2;i++){
        ans[2*i]=pos[i];
        ans[2*i+1]=neg[i];
    }
    return ans;
}

int main(){
    vector<int>arr={4,3,-1,9,-2,-5};
    vector<int>ans=rearrange_array(arr);
    for(auto itr: ans)cout<<itr<<" ";

    return 0;
}