#include<bits/stdc++.h>

using namespace std;

void set_zeroes(vector<vector<int>>&matrix,int n,int m){
    int col[m]={0};
    int row[n]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(row[i]==1 || col[j]==1){
                matrix[i][j]=0;
            }
        }
    }   
}

int main(){
    vector<vector<int>>matrix={
        {1,1,1,1},
        {1,0,0,1},
        {1,1,0,1},
        {1,1,1,1}
    };
    for(auto it:matrix){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }
    cout<<endl;
    int n=matrix.size();
    int m=matrix[0].size();
    set_zeroes(matrix,n,m);
    for(auto it:matrix){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}