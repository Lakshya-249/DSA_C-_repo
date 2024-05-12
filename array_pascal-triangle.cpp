#include<bits/stdc++.h>

using namespace std;

vector<int> generate_row(int row){
    long long ans=1;
    vector<int>ansrow;
    ansrow.push_back(ans);
    for(int col=1;col<row;col++){
        ans*=row-col;
        ans/=col;
        ansrow.push_back(ans);
    }
    return ansrow;
}

vector<vector<int>> pascle_triangle(int n){
    vector<vector<int>>ans;
    for(int i=1;i<=n;i++){
        ans.push_back(generate_row(i));
    }
    return ans;
}

int main(){
    vector<vector<int>>ans=pascle_triangle(6);
    for(auto it:ans){
        for(auto itr:it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}