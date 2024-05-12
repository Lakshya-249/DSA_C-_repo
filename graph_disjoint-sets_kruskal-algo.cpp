#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<pair<int,int>>* adj;
    public:
        graph(int n,int m){
            this->n=n;
            this->m=m;
            adj= new vector<pair<int,int>>[n+1];
        }
        vector<pair<int,int>>* create_graph(){
            cout<<"Enter the vertices and wieghts: ";
            for(int i=0;i<m;i++){
                int u,v,wt;
                cin>>u>>v>>wt;
                adj[u].push_back({v,wt});
                adj[v].push_back({u,wt});
            }
            return adj;
        }
        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<": ";
                for(auto it: adj[i]){
                    cout<<"{"<<it.first<<","<<it.second<<"} ";
                }
                cout<<endl;
            }
        }
};

class disjoint_set{
    private:
        vector<int>parent,size;
    public:
        disjoint_set(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
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
            if(parent[node1]==parent[node2]) return;

            if(size[node1]<size[node2]){
                parent[node1]= node2;
                size[node2]+= size[node1];
            }else{
                parent[node2]=node1;
                size[node1]+= size[node2];
            }
        }
};

class kruskal{
    public:
        int MST_Weight(vector<pair<int,int>>adj[],int v){
            vector<pair<int,pair<int,int>>>edges;
            for(int i=0;i<v+1;i++){
                for(auto it: adj[i]){
                    int adnode= it.first;
                    int node=i;
                    int wt= it.second;
                    edges.push_back({wt,{node,adnode}});
                }
            }
            sort(edges.begin(),edges.end());
            int sumwt=0;
            disjoint_set ds(v);
            for(auto it: edges){
                int wt1= it.first;
                int u= it.second.first;
                int v= it.second.second;
                if(ds.findupar(u)!=ds.findupar(v)){
                    sumwt = sumwt+ wt1;
                    ds.unionbysize(u,v);
                }
            }
            return sumwt;
        }
};

int main(){
    graph g1(6,9);
    vector<pair<int,int>>* adj= g1.create_graph();
    g1.display();
    kruskal ks1;
    int ans= ks1.MST_Weight(adj,6);
    cout<<"The minumum weight of the MST from the given graph is: "<<ans;

    return 0;
}

// 5 4 9
// 5 1 4
// 1 4 1
// 1 2 2
// 2 4 3
// 2 3 3
// 3 4 5
// 6 3 8
// 6 2 7