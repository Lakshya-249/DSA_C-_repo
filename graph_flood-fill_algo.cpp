#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        void dfs(int row,int col,int inicolor,int newcolor,
        vector<vector<int>>&ans,vector<vector<int>>image,int delrow[],int delcol[]){
            ans[row][col]=newcolor;
            int n=image.size();
            int m=image[0].size();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
                    dfs(nrow,ncol,inicolor,newcolor,ans,image,delrow,delcol);
                }
            }
        }
    public:
        vector<vector<int>> floodfill(vector<vector<int>>& image,int sr,int sc,int newcolor){
            vector<vector<int>> ans=image;
            int inicolor= image[sr][sc];
            int delrow[]={-1,0,+1,0};
            int delcol[]={0,+1,0,-1};
            dfs(sr,sc,inicolor,newcolor,ans,image,delrow,delcol);
            return ans;
        }
};

int main(){
    vector<vector<int>>image={
        {1,1,1},
        {2,2,0},
        {2,2,2}
    };
    for(auto it: image){
        for(auto itr: it)cout<<itr<<" ";
        cout<<endl;
    }
    graph g1;
    vector<vector<int>>ans=g1.floodfill(image,2,0,3);
    cout<<"Flooded amtrix is:\n";
    for(auto it: ans){
        for(auto itr: it)cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}