#include<bits/stdc++.h>

using namespace std;

vector<int> spiral_traversal(vector<vector<int>>&vec){
    int n=vec.size();
    int m=vec[0].size();
    int left=0,right=m-1;
    int top=0,bottom=n-1;
    vector<int>ans;
    while (top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++){
            ans.push_back(vec[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            ans.push_back(vec[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(vec[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(vec[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>mat={
        {1,2,3,4},
        {5,6,7,8},
        {9,4,8,1},
        {7,1,5,2}
    };
    for(auto it: mat){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }
    cout<<endl;
    vector<int>ans=spiral_traversal(mat);
    for(auto itr: ans) cout<<itr<<" ";

    return 0;
}