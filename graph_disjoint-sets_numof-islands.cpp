#include<bits/stdc++.h>

using namespace std;

class disjoint_set{
    public:
        vector<int>parent,size;
        disjoint_set(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i]= i;
                size[i]= 1;
            }
        }

        int findupar(int node){
            if(parent[node]==node) return node;
            return parent[node]= findupar(parent[node]);
        }

        void unionbysize(int u,int v){
            int node1= findupar(u);
            int node2= findupar(v);
            if(node1==node2) return;

            if(size[node1]<size[node2]){
                parent[node1]= node2;
                size[node2]+= size[node1];
            }else{
                parent[node2]= node1;
                size[node1]+= size[node2];
            }
        }   
};

class solution{
    private:
        bool isvalid(int nrow,int ncol,int n,int m){
            return (nrow>=0 && nrow<n && ncol>=0 && ncol<m);
        }
    public:
        vector<int> num_of_islands(vector<vector<int>>arr,int n,int m){
            disjoint_set ds(n*m-1);
            int vis[n][m];
            memset(vis,0, sizeof vis);
            int cnt=0;
            vector<int>ans;
            for(auto it: arr){
                int row= it[0];
                int col= it[1];
                if(vis[row][col]==1){
                    ans.push_back(cnt);
                    continue;
                }
                vis[row][col]= 1;
                cnt++;
                int dr[]= {0,-1,0,+1};
                int dc[]= {-1,0,+1,0};
                for(int i=0;i<4;i++){
                    int nrow= row+ dr[i];
                    int ncol= col+ dc[i];
                    if(isvalid(nrow,ncol,n,m)){
                        if(vis[nrow][ncol]){
                            int node= row*m + col;
                            int adnode= nrow*m + ncol;
                            if(ds.findupar(node)!=ds.findupar(adnode)){
                                cnt--;
                                ds.unionbysize(node,adnode);
                            }
                        }
                    }
                }
                ans.push_back(cnt);
            }
            return ans;
        }
};

int main(){
    vector<vector<int>>arr={{0,0},{0,1},{1,1},{1,0},{0,3},{1,3},{0,4},{3,2},{2,2},{1,2},{0,2}};
    solution sn1;
    vector<int>ans= sn1.num_of_islands(arr,4,5);

    for(auto it: ans) cout<<it<<" ";

    return 0;
}