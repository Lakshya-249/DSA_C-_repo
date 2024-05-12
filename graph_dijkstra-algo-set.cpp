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
            set<pair<int,int>>st;
            vector<int>distance(v+1,1e9);
            distance[src]=0;
            st.insert({0,src});
            while(!st.empty()){
                auto itr= *(st.begin());
                int node= itr.second;
                int wt= itr.first;
                st.erase(itr);
                for(auto it: adj[node]){
                    int n= it.first;
                    int w= it.second;
                    if(wt+w < distance[n]){
                        if(distance[n] != 1e9){
                            st.erase({distance[n],n});
                        }
                        distance[n]= wt+w;
                        st.insert({distance[n],n});
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