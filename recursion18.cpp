#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

class solution{
    void path(int i,int j,vector<string>&ans,vector<vector<int>>&vis,string moves,int n,vector<vector<int>>&m){
        if(i==n-1 && j==n-1){
            ans.push_back(moves);
            return;
        }
        //Downward 
        if(i+1<n && !vis[i+1][j] && m[i+1][j]==1){
            vis[i+1][j]=1;
            path(i+1,j,ans,vis,moves+'D',n,m);
            vis[i+1][j]=0;
        }
        //Left
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j-1]=1;
            path(i,j-1,ans,vis,moves+'L',n,m);
            vis[i][j-1]=0;
        }
        //Right
        if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j+1]=1;
            path(i,j+1,ans,vis,moves+'R',n,m);
            vis[i][j+1]=0;
        }
        //Upward
        if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i-1][j]=1;
            path(i-1,j,ans,vis,moves+'U',n,m);
            vis[i-1][j]=0;
        }

    }
    public:
        vector<string> findpath(vector<vector<int>>&m,int n){
            vector<vector<int>>vis(n,vector<int>(n,0));
            vector<string>ans;
            string moves="";
            if(m[0][0]==1) path(0,0,ans,vis,moves,n,m);
            return ans;
        }
};

int main() {
    int n = 4;

    vector < vector < int >> m = {{1,1,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    solution obj;
    vector < string > result = obj.findpath(m, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) cout << result[i] << endl;

  return 0;
}