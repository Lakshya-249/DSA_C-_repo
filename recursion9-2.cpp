#include<bits/stdc++.h>
#include<vector>
using namespace std;

void recur(int i, int s ,vector<int>&vec , int sum , int arr[],int n){
    if(i==n){
        if (s==sum){
            for(auto it:vec) cout<<it<<" ";
            cout<<endl;
        }
        return;
    }

    vec.push_back(arr[i]);
    s+=arr[i];
    recur(i+1,s,vec,sum,arr,n);
    s-=arr[i];
    vec.pop_back();
    recur(i+1,s,vec,sum,arr,n);
}

int main(){
    int sum=4;
    int arr[]={1,1,1,2,2};
    vector<int>vec;
    int n=sizeof(arr)/sizeof(int);
    recur(0,0,vec,sum,arr,n);
    return 0;
}