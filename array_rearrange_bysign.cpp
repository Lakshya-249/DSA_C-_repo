#include<bits/stdc++.h>

using namespace std;

vector<int> rearrange_array(vector<int>arr){
    int pos=0;
    int neg=1;
    vector<int>ans(arr.size(),0);
    for(auto itr:arr){
        if(itr<0){
            ans[neg]=itr;
            neg+=2;
        }else{
            ans[pos]=itr;
            pos+=2;
        }
    }
    return ans;
}

int main(){
    vector<int>arr={4,3,-1,9,-2,-5,8};
    vector<int>ans=rearrange_array(arr);
    for(auto itr: ans)cout<<itr<<" ";

    return 0;
}