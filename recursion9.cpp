#include<bits/stdc++.h>
#include<vector>
using namespace std;

void recur(int i,vector<int>&vec,int arr[],int n){
    int sum=0;
    if(i==n){
        for (auto it:vec){
            sum+=it;
        }
        if (sum==2 && vec.size()==2){
            for (auto xt:vec) cout<<xt<<" ";
            return;
        }
        return;
    }   
    vec.push_back(arr[i]);
    recur(i+1,vec,arr,n);
    vec.pop_back();
    recur(i+1,vec,arr,n);
}

int main(){
    int arr[]={1,2,0};
    vector<int>nvec;
    recur(0,nvec,arr,3);
    return 0;
}