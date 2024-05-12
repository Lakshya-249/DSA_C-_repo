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

class dijkstra{
    public:
        vector<int> path(vector<pair<int,int>>adj[],int v,int src,int end){
            int parent[v+1]={-1};
            parent[src]=src;
            vector<int>distance(v+1,1e9);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            distance[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                int node= pq.top().second;
                int wt= pq.top().first;
                pq.pop();
                for(auto it: adj[node]){
                    int n= it.first;
                    int w= it.second;
                    if(wt+w < distance[n]){
                        distance[n]= wt+w;
                        parent[n]=node;
                        pq.push({distance[n],n});
                    }
                }
            }
            int node= end;
            vector<int>ans;
            while(parent[node]!=node){
                ans.push_back(node);
                node=parent[node];
            }
            ans.push_back(src);
            return ans;
        }
};

int main(){
    graph g1(6,8);
    vector<pair<int,int>>*adj = g1.create_graph();
    g1.display();
    dijkstra dj1;
    vector<int>path= dj1.path(adj,6,0,6);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }

    return 0;
}

// 6 4 2
// 5 4 1
// 4 0 3
// 4 2 1
// 0 1 2
// 1 3 1
// 2 3 3
// 6 5 3