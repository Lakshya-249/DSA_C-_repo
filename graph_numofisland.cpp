#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>grid){
            vis[row][col]=1;
            queue<pair<int,int>>q;
            q.push({row,col});
            int n=grid.size();
            int m=grid[0].size();
            while(!q.empty()){
                int nrow=q.front().first;
                int ncol=q.front().second;
                q.pop();
                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        int nebrow=nrow+i;
                        int nebcol=ncol+j;
                        if(nebrow>=0 && nebrow<n && nebcol>=0 && nebcol<m && 
                        grid[nebrow][nebcol]==1 && !vis[nebrow][nebcol]){
                            vis[nebrow][nebcol]=1;
                            q.push({nebrow,nebcol});
                        }
                    }
                }
            }
        }
    public:
        int numofislands(vector<vector<int>>&grid){
            int n= grid.size();
            int m= grid[0].size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            int cnt=0;
            for(int row=0;row<n;row++){
                for(int col=0;col<m;col++){
                    if(!vis[row][col] && grid[row][col]==1){
                        cnt++;
                        bfs(row,col,vis,grid);
                    }
                }
            }
            return cnt;
        }
};

int main(){
    vector<vector<int>>grid={
        {0,0,1,1,0},
        {0,0,1,1,0},
        {0,0,1,0,0},
        {0,0,0,0,0},
        {1,1,0,0,1}
    };
    graph g1;
    int count=g1.numofislands(grid);
    cout<<"Number of islands: "<<count<<endl;
    return 0;
}