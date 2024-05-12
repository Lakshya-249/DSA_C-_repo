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
            cout<<"Enter the vertice and weight: ";
            for(int i=0;i<m;i++){
                int u,v,wt;
                cin>>u>>v>>wt;
                adj[u].push_back({v,wt});
            }
            return adj;
        }

        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<" : ";
                for(auto it: adj[i]) cout<<"{"<<it.first<<","<<it.second<<"} ";
                cout<<endl;
            }
        }
};

class bellman_ford{
    public: 
        vector<int> shortest_path(vector<pair<int,int>>adj[],int v,int src){
            vector<int>dist(v+1,1e9);
            dist[src]=0;
            vector<vector<int>>arr;
            for(int i=0;i<v+1;i++){
                for(auto it: adj[i]){
                    vector<int>seq;
                    seq.push_back(i);
                    seq.push_back(it.first);
                    seq.push_back(it.second);
                    arr.push_back(seq);
                    seq.clear();
                }
            }
            
            int sz= arr.size();

            for(int i=0;i<sz-1;i++){
                for(auto it: arr){
                    int u= it[0];
                    int v= it[1];
                    int wt= it[2];
                    if(dist[u]!=1e9 && dist[u]+ wt < dist[v]){
                        dist[v]= dist[u]+wt;
                    }
                }
            }
            // Check for (-)negative cycles..
            for(auto it: arr){
                int u= it[0];
                int v= it[1];
                int wt= it[2];
                if(dist[u]!=1e9 && dist[u]+wt < dist[v]){
                    return {-1};
                }
            }
            
            return dist;
        }
};

int main(){
    graph g1(5,7);
    vector<pair<int,int>>* adj= g1.create_graph();
    g1.display();
    bellman_ford bf1;
    vector<int>dist = bf1.shortest_path(adj,5,0);

    for(int i=0;i<dist.size();i++) cout<<i<<": "<<dist[i]<<endl;

    return 0;
}

// 0 1 5
// 1 2 -2
// 1 5 -3
// 5 3 1
// 3 2 6
// 3 4 -2
// 2 4 3