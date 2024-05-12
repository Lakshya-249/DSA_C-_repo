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

class floyd_warshall{
    public: 
        int min_city(vector<pair<int,int>>adj[],int v,int thres){
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
                        dist[i][j]= min(dist[i][j], dist[i][via]+dist[via][j]);
                    }
                }
            }

            int cnt=1e9;
            int city=-1;
            for(int i=0;i<v+1;i++){
                int temp=0;
                for(auto it: dist[i]){
                    if(it<=thres) temp++;
                }
                if(cnt==temp){
                    city= i;
                }else if(temp<cnt){
                    city= i;
                    cnt= temp;
                }

            }
            return city;
        }
};

int main(){
    graph g1(3,4);
    vector<pair<int,int>>* adj= g1.create_graph();
    g1.display();
    floyd_warshall fw1;
    int city = fw1.min_city(adj,3,4);
    cout<<"\nThe city with minimum flights available: "<<city;

    return 0;
}

// 0 1 3
// 1 2 1
// 2 3 1
// 1 3 4