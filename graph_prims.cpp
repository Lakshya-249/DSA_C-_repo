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

class prims{
    public:
        int spanning_tree(vector<pair<int,int>>adj[],int v){
            vector<int>vis(v+1,0);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            pq.push({0,0});
            int dis=0;
            while(!pq.empty()){
                int node= pq.top().second;
                int wt= pq.top().first;
                pq.pop();

                if(vis[node]==1) continue;
                vis[node]=1;
                dis+= wt;
                for(auto it: adj[node]){
                    int n= it.first;
                    int w= it.second;
                    if(!vis[n]){
                        pq.push({w,n});
                    }
                }
            }
            return dis;
        }
};

int main(){
    graph g1(4,6);
    vector<pair<int,int>>* adj= g1.create_graph();
    g1.display();
    prims pm1;
    int ans= pm1.spanning_tree(adj,4);
    cout<<"The minimum cost of the MST from given graph: "<<ans;

    return 0;
}