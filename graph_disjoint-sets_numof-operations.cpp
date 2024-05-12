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
            if(parent[node] == node){
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

class operations{
    public:
        int solution(vector<vector<int>>arr, int v){
            disjoint_set ds(v);
            int cntextr= 0;
            for(auto it: arr){
                int u= it[0];
                int v= it[1];
                if(ds.findupar(u) == ds.findupar(v)){
                    cntextr++;
                }else{
                    ds.unionbysize(u,v);
                }
            }
            int cp=0;
            for(int i=0;i<v+1;i++){
                if(ds.parent[i]==i) cp++;
            }
            int ans= cp-1;
            if(cntextr>=ans) return ans;
            return -1;
        }
};

int main(){
    vector<vector<int>>arr={
        {0,1},
        {0,2},
        {0,3},
        {1,2},
        {2,3},
        {4,5},
        {5,6},
        {7,8}
    };

    operations op1;
    int ans= op1.solution(arr,8);
    cout<<"The number of edeges required to connect all connected components: "<<ans;

    return 0;
}