#include<bits/stdc++.h>

using namespace std;

void rotate_matrix(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(){
    vector<vector<int>>matrix={
        {1,2,3,4},
        {5,6,7,8},
        {9,4,8,1},
        {7,1,5,2}
    };
    for(auto it: matrix){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }
    cout<<endl;
    rotate_matrix(matrix);
    for(auto it: matrix){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}