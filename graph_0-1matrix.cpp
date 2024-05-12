#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
        vector<vector<int>> matrix_distancecell(vector<vector<int>>&grid){
            int n= grid.size();
            int m= grid[0].size();
            queue<pair<pair<int,int>,int>>q;
            vector<vector<int>>vis(n,vector<int>(m,0));
            vector<vector<int>>dist(n,vector<int>(m,0));
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]){
                        q.push({{i,j},0});
                        vis[i][j]=1;
                    }
                }
            }

            int delrow[]= {-1,0,+1,0};
            int delcol[]= {0,+1,0,-1};

            while(!q.empty()){
                int row= q.front().first.first;
                int col= q.front().first.second;
                int steps= q.front().second;
                q.pop();
                dist[row][col]=steps;

                for(int i=0;i<4;i++){
                    int nrow= row + delrow[i];
                    int ncol= col + delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                    !vis[nrow][ncol] && grid[nrow][ncol]==0){
                        q.push({{nrow,ncol},steps+1});
                        vis[nrow][ncol]=1;
                    }
                }
            }
            return dist;
        }
};

int main(){
    vector<vector<int>>grid={
        {0,0,0},
        {0,1,0},
        {1,0,1}
    };
    for(auto it: grid){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }
    graph g1;
    vector<vector<int>>ans=g1.matrix_distancecell(grid);
    cout<<"The answer matrix:\n";
    for(auto it: ans){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}