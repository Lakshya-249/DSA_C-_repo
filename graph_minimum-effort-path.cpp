#include<bits/stdc++.h>

using namespace std;

class dijkstra{
    public:
        int minimum_effortpath(vector<vector<int>>maze, pair<int,int>src, pair<int,int>des){
            int n= maze.size();
            int m= maze[0].size();
            vector<vector<int>>dist(n,vector<int>(m,1e9));
            priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
            dist[src.first][src.second]= 0;
            pq.push({0,{src}});
            int drow[]= {0,-1,0,+1};
            int dcol[]= {-1,0,+1,0};
            while(!pq.empty()){
                int row= pq.top().second.first;
                int col= pq.top().second.second;
                int diff= pq.top().first;
                int wt= maze[row][col];
                pq.pop();
                for(int i=0;i<4;i++){
                    int nrow= row+ drow[i];
                    int ncol= col+ dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                        int effrt= max(abs(maze[nrow][ncol]-wt),diff);
                        if(effrt< dist[nrow][ncol]){
                            dist[nrow][ncol]= effrt;
                            pq.push({effrt,{nrow,ncol}});
                        }
                    }
                }
            }
            return dist[des.first][des.second];
        }
};

int main(){
    vector<vector<int>>maze={
        {1,2,2},
        {3,8,2},
        {5,3,5}  
    };
    pair<int,int>src= {0,0};
    pair<int,int>des= {1,1};
    dijkstra dj1;
    int distance = dj1.minimum_effortpath(maze,src,des);
    cout<<"The minimum effort path for following maze is: "<<distance;
    cout<<"The minimum effort path for following maze is: "<<distance;

    return 0;
}