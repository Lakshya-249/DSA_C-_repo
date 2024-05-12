#include<bits/stdc++.h>

using namespace std;

class disjoint_set{
    vector<int>rank,parent,size;
    public:
        disjoint_set(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<n+1;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findupar(int node){
            if(parent[node]==node){
                return node;
            }
            return parent[node] = findupar(parent[node]);
        }

        void unionbyrank(int u,int v){
            int node1= findupar(u);
            int node2= findupar(v);
            if(parent[node1]==parent[node2]) return;
            if(rank[node1]<rank[node2]){
                parent[node1]=node2;
            }else if(rank[node1]>rank[node2]){
                parent[node2]= node1;
            }else{
                parent[node1]=node2;
                rank[node1]++;
            }
        }

        void unionbysize(int u,int v){
            int up_u= findupar(u);
            int up_v= findupar(v);
            if(parent[up_u]==parent[up_v]) return;
            if(size[up_u]<size[up_v]){
                parent[up_u]= up_v;
                size[up_v]+= size[up_u];
            }else if(size[up_v]<size[up_u]){
                parent[up_v]= up_u;
                size[up_u]+= size[up_v];
            }else{
                parent[up_v]= up_u;
                size[up_u]+= size[up_v];
            }
        }
};

int main(){
    disjoint_set dsj1(7);
    dsj1.unionbyrank(1,2);
    dsj1.unionbyrank(2,3);
    dsj1.unionbyrank(4,5);
    dsj1.unionbyrank(6,7);
    dsj1.unionbyrank(5,6);
    if(dsj1.findupar(3)==dsj1.findupar(7)){
        cout<<"Same\n";
    }else cout<<"Not Same\n";
    dsj1.unionbyrank(3,7);
    if(dsj1.findupar(3)==dsj1.findupar(7)){
        cout<<"Same\n";
    }else cout<<"Not Same\n";

    disjoint_set ds2(7);
    ds2.unionbysize(1,2);
    ds2.unionbysize(2,3);
    ds2.unionbysize(4,5);
    ds2.unionbysize(6,7);
    ds2.unionbysize(5,6);
    if(ds2.findupar(3)==ds2.findupar(7)){
        cout<<"Same\n";
    }else cout<<"Not Same\n";
    ds2.unionbysize(3,7);
    if(ds2.findupar(3)==ds2.findupar(7)){
        cout<<"Same\n";
    }else cout<<"Not Same\n";

    return 0;
}