#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        void dfs(int row,int col,vector<vector<char>>mat,vector<vector<int>>&vis){
            vis[row][col]=1;
            int n=mat.size();
            int m=mat[0].size();
            int delrow[]={-1,0,+1,0};
            int delcol[]={0,+1,0,-1};

            for(int i=0;i<4;i++){
                int nrow= row+delrow[i];
                int ncol= col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                !vis[nrow][ncol] && mat[nrow][ncol]=='o'){
                    dfs(nrow,ncol,mat,vis);
                }
            }
        }
    public:
        vector<vector<char>> fillmatrix(vector<vector<char>>&mat){
            int n= mat.size();
            int m= mat[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));

            for(int i=0;i<m;i++){
                if(mat[0][i]=='o') dfs(0,i,mat,vis);
                if(mat[n-1][i]=='o') dfs(n-1,i,mat,vis);
            }

            for(int j=0;j<n;j++){
                if(mat[j][0]=='o') dfs(j,0,mat,vis);
                if(mat[j][m-1]=='o') dfs(j,m-1,mat,vis);
            }

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && mat[i][j]=='o'){
                        mat[i][j]='x';
                    }
                }
            }
            return mat;
        }
};

int main(){
    vector<vector<char>>mat={
        {'x','x','x','x','x'},
        {'x','o','o','x','o'},
        {'x','x','o','x','o'},
        {'x','o','x','o','x'},
        {'o','o','x','x','x'}
    };
    for(auto it: mat){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }
    graph g1;
    vector<vector<char>>ans= g1.fillmatrix(mat);
    cout<<"The answer matrix:\n";
    
    for(auto it: ans){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}