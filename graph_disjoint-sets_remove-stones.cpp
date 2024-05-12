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
    public:
        int most_stones_removed(vector<vector<int>>arr,int n){
            int maxrow= 0;
            int maxcol= 0;
            for(auto it: arr){
                maxrow= max(maxrow,it[0]);
                maxcol= max(maxcol,it[0]);
            }
            disjoint_set ds(maxrow+maxcol+1);
            unordered_map<int,int>mpp;
            for(auto it: arr){
                int noderow= it[0];
                int nodecol= it[1] + maxrow + 1;
                ds.unionbysize(noderow,nodecol); 
                mpp[noderow]=1;
                mpp[nodecol]=1;
            }
            int cnt=0;
            for(auto it: mpp){
                if(ds.findupar(it.first)==it.first) cnt++;
            }

            return n-cnt;
        }
};

int main(){
    vector<vector<int>>arr= {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    solution s1;
    int ans= s1.most_stones_removed(arr,6);
    cout<<"The number of stones that can be removed are: "<<ans;

    return 0;
}