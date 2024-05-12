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
        vector<int> shortest_path(vector<pair<int,int>>adj[],int v,int src){
            vector<int>distance(v+1,INT_MAX);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            distance[src]=0;
            pq.push({0,src});
            while(!pq.empty()){
                int wt = pq.top().first;
                int node= pq.top().second;
                pq.pop();

                for(auto it: adj[node]){
                    int w = it.second;
                    int n = it.first;
                    if(wt+w < distance[n]){
                        distance[n] = wt+w;
                        pq.push({wt+w,n});
                    }
                }
            }
            return distance;
        }
};

int main(){
    graph g1(6,8);
    vector<pair<int,int>>*adj = g1.create_graph();
    g1.display();
    dijkstra dj1;
    vector<int>distance= dj1.shortest_path(adj,6,3);
    for(int i=0;i<distance.size();i++){
        cout<<i<<" : "<<distance[i];
        cout<<endl;
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