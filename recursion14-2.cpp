#include<bits/stdc++.h>
#include<vector>
using namespace std;

class solution{
    private:
        void recur_(int i,vector<int>&arr,vector<vector<int>>&vec,int n){
            if(i==n){
                vec.push_back(arr);
                return;
            }
            for(int x=i;x<n;x++){
                swap(arr[i],arr[x]);
                recur_(i+1,arr,vec,n);
                swap(arr[i],arr[x]);
            }
        }
    public:
        vector<vector<int>> recur(vector<int>&arr){
            vector<vector<int>>vec;
            int n=arr.size();
            recur_(0,arr,vec,n);
            return vec;
        }
};

int main(){
    vector<int>arr={1,2,3,4};
    vector<vector<int>>vec;
    solution s1;
    vec=s1.recur(arr);
    for(auto it=vec.begin();it!=vec.end();it++){
        for(auto vc: *it) cout<<vc;
        cout<<endl;
    }
    return 0;
}