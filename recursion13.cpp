#include<bits/stdc++.h>
#include<vector>
using namespace std;

class subset{
    private:
        void recur_(int ind,vector<vector<int>>&vec,vector<int>&ds,vector<int>arr,int n){
            if(ind==n){
                auto it=find(vec.begin(),vec.end(),ds);
                if(it == vec.end()){
                    vec.push_back(ds);
                }
                return;
            }
            ds.push_back(arr[ind]);
            recur_(ind+1,vec,ds,arr,n);
            ds.pop_back();
            recur_(ind+1,vec,ds,arr,n);
        }
    public:
        vector<vector<int>> recur(vector<int>arr){
            int n=arr.size();
            vector<vector<int>>vec;
            vector<int>ds;
            sort(arr.begin(),arr.end());
            recur_(0,vec,ds,arr,n);
            return vec;
        }
};

int main(){
    vector<int>arr={2,1,2,3,2,3,4};
    subset s1;
    vector<vector<int>>nvec;
    nvec=s1.recur(arr);
    for (int i = 0; i < nvec.size(); i++) {
        for (int j = 0; j < nvec[i].size(); j++){
            cout << nvec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}