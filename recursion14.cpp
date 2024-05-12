#include<bits/stdc++.h>
#include<vector>
using namespace std;

class solution{
    private:
        void recur_(vector<int>&vec,vector<int>&arr,vector<vector<int>>&nvec,int map[]){
            if(vec.size()==arr.size()){
                nvec.push_back(vec);
                return;
            }

            for (int i=0;i<arr.size();i++){
                if(!map[i]){
                    map[i]=1;
                    vec.push_back(arr[i]);
                    recur_(vec,arr,nvec,map);
                    map[i]=0;
                    vec.pop_back();
                }
            }
        }
    public:
        vector<vector<int>> recur(vector<int>&arr){
            vector<int>vec;
            vector<vector<int>>nvec;
            int map[arr.size()]={0};
            recur_(vec,arr,nvec,map);
            return nvec;
        }
};

int main(){
    vector<int>arr={1,2,3};
    solution s1;
    vector<vector<int>>s_vec=s1.recur(arr);
    for (auto it=s_vec.begin();it!=s_vec.end();it++){
        for(auto vc:*it) cout<<vc<<" ";
        cout<<endl;
    }
    return 0;
}