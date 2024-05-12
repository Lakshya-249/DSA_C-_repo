#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool recur(int i, int s ,vector<int>&vec , int sum , int arr[],int n){
    if(i==n){
        if (s==sum){
            for(auto it:vec) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        return false;
    }

    vec.push_back(arr[i]);
    s+=arr[i];
    if (recur(i+1,s,vec,sum,arr,n)==true) return true;
    s-=arr[i];
    vec.pop_back();
    if (recur(i+1,s,vec,sum,arr,n)==true) return true;
    return false;
}

int main(){
    int sum=2;
    int arr[]={1,2,1};
    vector<int>vec;
    int n=sizeof(arr)/sizeof(int);
    recur(0,0,vec,sum,arr,n);
    return 0;
}