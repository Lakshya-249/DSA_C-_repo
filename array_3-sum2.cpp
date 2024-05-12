#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> find_3sum(vector<int>arr){
    int n=arr.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        set<int>hashset;
        for(int j=i+1;j<n;j++){
            int res=0-arr[i]-arr[j];
            if(hashset.find(res)!=hashset.end()){
                vector<int>temp;
                temp={arr[i],arr[j],res};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
}

int main(){
    // vector<int>arr={-2,-2,-2,-1,-1,-1,2,0,0,0,2,2,2};
    vector<int>arr={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=find_3sum(arr);
    cout<<"Unique 3 elements which gives zeroes: "<<endl;
    for(auto it: ans){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}