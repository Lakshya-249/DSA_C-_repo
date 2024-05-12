#include<bits/stdc++.h>
#include<vector>
using namespace std;

class solution{
    private:
        void recur_(int ind,vector<int>&arr,vector<vector<int>>&vec,vector<int>&nvec,int targ){
            if(targ==0){
                vec.push_back(nvec);
                return;
            }

            for(int i=ind;i<arr.size();i++){
                if(i>ind && arr[i]==arr[i-1]) continue;
                if(arr[i]>targ) break;
                nvec.push_back(arr[i]);
                recur_(i+1,arr,vec,nvec,targ-arr[i]);
                nvec.pop_back();
            }
        }
    public:
        vector<vector<int>> recur(vector<int>&arr,int targ){
            vector<int>nvec;
            vector<vector<int>>vec;
            sort(arr.begin(),arr.end());
            recur_(0,arr,vec,nvec,targ);
            return vec;
        }
};

int main(){
    vector<int>arr={1,1,2,1,2};
    solution s1;
    vector<vector<int>>vec;
    vec=s1.recur(arr,4);
    for(auto it=vec.begin();it!=vec.end();it++){
        for(auto vc: *it) cout<<vc<<" ";
        cout<<endl;
    }
    return 0;
}