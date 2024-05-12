#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        void dfs(int row,int col,vector<vector<int>>grid,
        vector<vector<int>>&vis,vector<pair<int,int>>&vec,int row0,int col0){
            vis[row][col]=1;
            int n= grid.size();
            int m= grid[0].size();
            int delrow[]= {-1,0,+1,0};
            int delcol[]= {0,+1,0,-1};
            vec.push_back({row0-row,col0-col});
            for(int i=0;i<4;i++){
                int nrow= row+delrow[i];
                int ncol= col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    dfs(nrow,ncol,grid,vis,vec,row0,col0);
                }
            }
        }

    public:
        int num_distinctislands(vector<vector<int>>grid){
            int n= grid.size();
            int m= grid[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            set<vector<pair<int,int>>>st;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j] && grid[i][j]==1){
                        vector<pair<int,int>>vec;
                        dfs(i,j,grid,vis,vec,i,j);
                        st.insert(vec);
                    }
                }
            }
            return st.size();
        }
};

int main(){
    vector<vector<int>>grid={
        {1,1,0,1,1},
        {1,0,0,0,0},
        {0,0,0,1,1},
        {1,1,0,1,1}
    };

    graph g1;
    int ans= g1.num_distinctislands(grid);
    cout<<"The number of distinct islands: "<<ans;

    return 0;
}