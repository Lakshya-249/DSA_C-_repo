#include<bits/stdc++.h>
#include<vector>
using namespace std;

void recur(int i,vector<int>&vec,int arr[],int n){
    if (i==n){
        for(auto it: vec) cout<<it<<" ";
        cout<<endl;
        return;
    }
    vec.push_back(arr[i]);
    recur(i+1,vec,arr,n);
    vec.pop_back();
    recur(i+1,vec,arr,n);
}


int main(){
    int ind;
    cout<<"enter length of array : ";
    cin>>ind;
    vector<int>vec;
    int arr[ind];
    for(int x=0;x<ind;x++) cin>>arr[x];
    recur(0,vec,arr,ind);
    return 0;
}