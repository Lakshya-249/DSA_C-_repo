#include<bits/stdc++.h>

using namespace std;

class dijkstra{
    public:
        int shortest_distance(vector<vector<int>>maze, pair<int,int>src, pair<int,int>des){
            int n= maze.size();
            int m= maze[0].size();
            vector<vector<int>>dist(n,vector<int>(m,1e9));
            dist[src.first][src.second]=0;
            queue<pair<int,pair<int,int>>>pq;
            pq.push({0,{src}});
            int drow[]= {0,-1,0,+1};
            int dcol[]= {-1,0,+1,0};
            while(!pq.empty()){
                int wt= pq.front().first;
                int row= pq.front().second.first;
                int col= pq.front().second.second;
                pq.pop();

                for(int i=0;i<4;i++){
                    int nrow= row + drow[i];
                    int ncol= col + dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol]==1){
                        if(wt+1 < dist[nrow][ncol]){
                            dist[nrow][ncol] = wt+1;
                            pq.push({wt+1,{nrow,ncol}});
                        }
                    }
                }
            }
            int row= des.first;
            int col= des.second;
            if(dist[row][col]==1e9) return -1;
            return dist[row][col];
        }
};

int main(){
    vector<vector<int>>maze={
        {1,1,1,1},
        {1,1,0,1},
        {1,1,1,1},
        {1,1,0,0},
        {1,0,0,0}
    };
    pair<int,int>src={0,1};
    pair<int,int>des={2,3};
    dijkstra dj1;
    int distance= dj1.shortest_distance(maze,src,des);
    cout<<"The shortest distance for the following maze is: "<<distance;

    return 0;
}