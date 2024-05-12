#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

class solution{
    void path(int i,int j,vector<string>&ans,vector<vector<int>>&vis,
    string moves,int n,vector<vector<int>>&m,int di[],int dj[]){
        if(i==n-1 && j==n-1){
            ans.push_back(moves);
            return;
        }
        string direc="DLRU";
        for(int ind=0;ind<n;ind++){
            int nexti=i+di[ind];
            int nextj=j+dj[ind];
            if(nexti<n && nextj<n && nexti>=0 && nextj>=0 && !vis[nexti][nextj] && m[nexti][nextj]==1){
                vis[nexti][nextj]=1;
                path(nexti,nextj,ans,vis,moves+direc[ind],n,m,di,dj);
                vis[nexti][nextj]=0;
            }
        }
    }
    public:
        vector<string> findpath(vector<vector<int>>&m,int n){
            vector<vector<int>>vis(n,vector<int>(n,0));
            vector<string>ans;
            string moves="";
            int di[]={1,0,0,-1};
            int dj[]={0,-1,1,0};
            if(m[0][0]==1) path(0,0,ans,vis,moves,n,m,di,dj);
            return ans;
        }

};

int main() {
    int n = 4;

    vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

    solution obj;
    vector < string > result = obj.findpath(m, n);
    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++) cout << result[i] << endl;

  return 0;
}