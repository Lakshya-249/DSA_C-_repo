#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> find_3sum(vector<int>arr){
    int n=arr.size();
    set<vector<int>>st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
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