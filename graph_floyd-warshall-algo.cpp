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

class floyd_warshall{
    public:
        vector<vector<int>> shortest_paths(vector<pair<int,int>>adj[],int v){
            vector<vector<int>>dist(v+1,vector<int>(v+1,1e9));
            for(int i=0;i<v+1;i++){
                dist[i][i]=0;
            }
            for(int i=0;i<v+1;i++){
                for(auto it: adj[i]){
                    dist[i][it.first]= it.second;
                }
            }
            for(int via=0;via<v+1;via++){
                for(int i=0;i<v+1;i++){
                    for(int j=0;j<v+1;j++){
                        dist[i][j]= min(dist[i][via]+ dist[via][j], dist[i][j]);
                    }
                }
            }
            for(int i=0;i<v+1;i++){
                for(int j=0;j<v+1;j++){
                    if(dist[i][j]==1e9){
                        dist[i][j]=-1;
                    }
                }
            }
            // Checking negative cycles...
            for(int i=0;i<v+1;i++){
                if(dist[i][i]<0){
                    return {{-1}};
                }
            }

            return dist;
        }
};

int main(){
    graph g1(3,6);
    vector<pair<int,int>>* adj= g1.create_graph();
    g1.display();
    floyd_warshall fw1;
    vector<vector<int>>dist= fw1.shortest_paths(adj,3);
    cout<<"\n";
    for(auto it: dist){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}

// 0 1 2
// 1 0 1
// 1 2 3
// 3 2 4
// 3 1 5
// 3 0 3