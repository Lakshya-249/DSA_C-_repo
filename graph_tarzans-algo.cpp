#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<int>* adj;
    public:
        graph(int n,int m){
            this->n= n;
            this->m= m;
            adj= new vector<int>[n+1];
        }
        vector<int>* create_graph(){
            cout<<"Enter the connected vertices: ";
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
        }
        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<" : {";
                for(auto it: adj[i]) cout<<it<<",";
                cout<<"}"<<endl;
            }
        }
};

class tarzan_algo{
    private:
        int timer=1;
        void dfs(int node,int parent,vector<int>adj[],
        vector<vector<int>>&bridge,vector<int>&vis,int low[],int tim[]){
            vis[node]=1;
            tim[node]=low[node]=timer;
            timer++;
            for(auto it: adj[node]){
                if(it==parent) continue;
                if(vis[it]==0){
                    dfs(it,node,adj,bridge,vis,low,tim);
                    low[node]= min(low[it],low[node]);
                    if(low[it]>tim[node]){
                        bridge.push_back({it,node});
                    }
                }else{
                    low[node]= min(low[it],low[node]);
                }
            }
        }
    public:
        vector<vector<int>> birdges_ingraph(vector<int>adj[],int v){
            vector<int>vis(v+1,0);
            int low[v+1];
            int tim[v+1];
            vector<vector<int>>bridge;
            dfs(0,-1,adj,bridge,vis,low,tim);   
            return bridge;
        }
};

int main(){
    vector<int>*adj;
    graph g1(9,12);
    adj= g1.create_graph();
    g1.display();
    tarzan_algo tz1;
    vector<vector<int>>ans= tz1.birdges_ingraph(adj,12);
    for(auto it: ans){
        cout<<"{";
        for(auto itr: it)cout<<itr<<",";
        cout<<"}"<<endl;
    }

    return 0;
}

// 0 1
// 1 2
// 2 0
// 1 3 
// 3 4
// 4 5
// 5 6
// 6 4
// 5 7
// 7 8
// 8 9
// 9 7