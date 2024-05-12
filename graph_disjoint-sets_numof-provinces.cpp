#include<bits/stdc++.h>

using namespace std;

class disjoint_set{
    public:
        vector<int>parent,size;
        disjoint_set(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                size[i]=1;
                parent[i]=i;
            }
        }

        int findupar(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node]= findupar(parent[node]);
        }

        void unionbysize(int u,int v){
            int node1= findupar(u);
            int node2= findupar(v);
            if(node1 == node2) return;
            if(size[node1]<size[node2]){
                parent[node1]= node2;
                size[node2]+= size[node1];
            }else{
                parent[node2]= node1;
                size[node1]+= size[node2];
            }
        }
};

class provinces{
    public:
        int numofprovinces(vector<vector<int>>arr,int v){
            disjoint_set ds(v);
            for(int i=0;i<v+1;i++){
                for(int j=0;j<v+1;j++){
                    if(arr[i][j]==1){
                        ds.unionbysize(i,j);
                    }
                }
            }

            int cnt=0;
            for(int i=0;i<v+1;i++){
                if(ds.parent[i]==i) cnt++;
            }

            return cnt;
        }
};

int main(){
    vector<vector<int>>arr= {
        {0,1,0,0,0,0,0},
        {1,0,1,0,0,0,0},
        {0,1,0,0,0,0,0},
        {0,0,0,0,1,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,0,0,0,1},
        {0,0,0,0,0,1,0}
    };
    provinces pv1;
    int ans= pv1.numofprovinces(arr,6);
    cout<<"The number of provinces in the given adjency matrix is: "<<ans;

    return 0;
}