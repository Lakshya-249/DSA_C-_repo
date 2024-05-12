#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
        int rottingtime(vector<vector<int>>&grid){
            int n= grid.size();
            int m= grid[0].size();

            int cntfresh=0;
            queue<pair<pair<int,int>,int>>q;
            int vis[n][m];
            for(int row=0;row<n;row++){
                for(int col=0;col<m;col++){
                    if(grid[row][col]==2){
                        q.push({{row,col},0});
                        vis[row][col]=2;
                    }else{
                        vis[row][col]=0;
                    }
                    if(grid[row][col]==1)cntfresh++;
                }
            }
            int tm=0;
            int cnt=0;
            int delrow[]= {-1,0,+1,0};
            int delcol[]= {0,+1,0,-1};
            while(!q.empty()){
                int r= q.front().first.first;
                int c= q.front().first.second;
                int t= q.front().second;
                q.pop();
                tm= max(tm,t);

                for(int i=0;i<4;i++){
                    int nrow= r+delrow[i];
                    int ncol= c+delcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                        q.push({{nrow,ncol},t+1});
                        vis[nrow][ncol]=2;
                        cnt++;
                    }
                }
            }
            if(cnt!=cntfresh) return-1;
            else return tm;
        }
};

int main(){
    vector<vector<int>>grid={
        {0,1,2},
        {0,1,1},
        {2,0,1}
    };
    graph g1;
    int time= g1.rottingtime(grid);
    cout<<"The time required to rott all the elements: "<<time;

    return 0;
}