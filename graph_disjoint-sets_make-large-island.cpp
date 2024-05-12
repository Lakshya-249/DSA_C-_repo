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
        bool isvalid(int nrow,int ncol,int n){
            return (nrow>=0 && nrow<n && ncol>=0 && ncol<n);
        }
    public:
        int maxsize(vector<vector<int>>&arr){
            int n= arr.size();
            disjoint_set ds(n*n -1);
            int dr[]= {0,-1,0,+1};
            int dc[]= {-1,0,+1,0};
            for(int row=0;row<n;row++){
                for(int col=0;col<n;col++){
                    if(arr[row][col]==0) continue;;
                    for(int i=0;i<4;i++){
                        int nrow= row+ dr[i];
                        int ncol= col+ dc[i];
                        if(isvalid(nrow,ncol,n) && arr[nrow][ncol]==1){
                            int node= row*n + col;
                            int adnode= nrow*n + ncol;
                            ds.unionbysize(node,adnode);
                        }
                    }
                }
            }

            int maxsz=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(arr[i][j]==1) continue;
                    set<int>temp;
                    for(int k=0;k<4;k++){
                        int nrow= i+ dr[k];
                        int ncol= j+ dc[k];
                        if(isvalid(nrow,ncol,n) && arr[nrow][ncol]==1){
                            int node= nrow*n + ncol;
                            temp.insert(ds.findupar(node));
                        }
                    }
                    int sz=0;
                    for(auto it: temp){
                        sz += ds.size[it];
                    }
                    maxsz= max(maxsz,sz+1);
                }
            }
            // return maxsz;
            for(int i=0;i<n*n;i++){
                maxsz= max(maxsz, ds.size[ds.findupar(i)]);
            }
            return maxsz;
        }
};

int main(){
    vector<vector<int>>arr={
        {1,1,0,1,1,0},
        {1,1,0,1,1,0},
        {1,1,0,1,1,0},
        {0,0,1,0,0,0},
        {0,0,1,1,1,0},
        {0,0,1,1,1,0}
    };
    solution s1;
    int ans= s1.maxsize(arr);
    cout<<"The largest island that can be formed using given adjency matrix of group of islands is: "<<ans;

    return 0;
}