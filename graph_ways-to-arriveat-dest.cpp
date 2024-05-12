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
        int number_shortestpaths(vector<pair<int,int>>adj[],int start,int end,int v){
            vector<int>distance(v+1,1e9), path(v+1,0);
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
            pq.push({0,start});
            distance[start]=0;
            path[start]=1;
            int mod= (int)(1e9 + 7);
            while(!pq.empty()){
                int node= pq.top().second;
                int wt= pq.top().first;
                pq.pop();
                for(auto it: adj[node]){
                    int n= it.first;
                    int w= it.second;
                    if(wt+w< distance[n]){
                        distance[n]= wt+w;
                        pq.push({wt+w,n});
                        path[n]=path[node];
                    }else if(wt+w == distance[n]){
                        path[n]= (path[n]+path[node])%mod;
                    }
                }
            }
            return path[end]%mod;
        }
};

int main(){
    graph g1(8,13);
    vector<pair<int,int>>* adj= g1.create_graph();
    g1.display();
    dijkstra dj1;
    int paths= dj1.number_shortestpaths(adj,0,8,8);
    cout<<"The number of shortest paths for given graph is: "<<paths;

    return 0;
}

// 0 1 1
// 0 2 2
// 0 3 1
// 0 4 2
// 1 5 2
// 2 5 1
// 3 5 2
// 3 7 3
// 3 6 2
// 4 6 1
// 5 8 1
// 7 8 1
// 6 8 1