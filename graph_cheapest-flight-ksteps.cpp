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

        vector<pair<int,int>>* create_DAG(){
            cout<<"Enter the vertices and the weights between edges: ";
            for(int i=0;i<m;i++){
                int u,v,wt;
                cin>>u>>v>>wt;
                adj[u].push_back({v,wt});
            }
            return adj;
        }
        
        void display(){
            for(int i=0;i<=n;i++){
                cout<<i<<" : ";
                for(auto it: adj[i]) cout<<"{"<<it.first<<","<<it.second<<"} ";
                cout<<endl;
            }
        }
};

class dijkstra{
    public:
        int cheapest_flight_ksteps(vector<pair<int,int>>adj[],int v,int src,int des,int k){
            vector<int>dist(v+1,1e9);
            dist[src]=0;
            queue<pair<int,pair<int,int>>>q;
            q.push({0,{src,0}});
            while(!q.empty()){
                auto it= q.front();
                q.pop();
                int node= it.second.first;
                int wt= it.second.second;
                int steps= it.first;
                if(steps>k) continue;

                for(auto itr: adj[node]){
                    int n= itr.first;
                    int w= itr.second;
                    if(wt+w<dist[n] && steps<k){
                        dist[n]= w+wt;
                        q.push({steps+1,{n,dist[n]}});
                    }
                }
            }
            if(dist[des]==1e9) return -1;
            return dist[des];
        }
};

int main(){
    graph g1(5,6);
    vector<pair<int,int>>* adj= g1.create_DAG();
    g1.display();
    dijkstra dj1;
    int ans= dj1.cheapest_flight_ksteps(adj,5,0,2,3);
    cout<<"The cheapest flight within k steps is: "<<ans;

    return 0;
}

// 0 1 5
// 0 3 2
// 3 1 2
// 1 2 5
// 1 4 1
// 4 2 1