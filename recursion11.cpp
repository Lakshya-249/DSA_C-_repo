#include<bits/stdc++.h>
using namespace std;

void recur(int i, int s ,vector<int>&vec , int sum , int arr[],int n,set<vector<int>>&st){
    if(i==n){
        if (s==sum){
            st.insert(vec);
        }
        return;
    }
    vec.push_back(arr[i]);
    s+=arr[i];
    recur(i+1,s,vec,sum,arr,n,st);
    s-=arr[i];
    vec.pop_back();
    recur(i+1,s,vec,sum,arr,n,st);
}

void Print_Vector(vector<int>vec){
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return;
}

int main(){
    set<vector<int>>st;
    vector<int>vec;
    int sum=4;
    int arr[]={1,1,1,2,2};
    int n=sizeof(arr)/sizeof(int);
    recur(0,0,vec,sum,arr,n,st);
    for(auto it=st.begin();it!=st.end();it++){
        Print_Vector(*it);
    }
}