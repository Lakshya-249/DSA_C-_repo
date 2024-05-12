#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<int>*adj;
    public:
        graph(int a,int b){
            n=a;
            m=b;
            adj= new vector<int>[n+1];
        }

        vector<int>* create_graph(){
            cout<<"Enter the data: ";
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
                cout<<i<<": ";
                for(auto it: adj[i]) cout<<it<<" ";
                cout<<endl;
            }
        }
};

class bipartite{
    private:
        bool solve(int node,int col,int color[],vector<int>adj[]){
            color[node]=col;
            
            for(auto it: adj[node]){
                if(color[it]==-1){
                    if(solve(it,!col,color,adj)==false) return false;
                }else if(color[it]==col){
                    return false;
                }
            }
            return true;
        }
    public:
        bool isbarpatite(int v,vector<int>adj[]){
            int color[v+1];
            for(int i=0;i<v+1;i++) color[i]=-1;

            for(int i=0;i<v+1;i++){
                if(color[i]==-1){
                    if(solve(i,0,color,adj)==false) return false;
                }
            }
            return true;
        }
};

int main(){
    graph g1(8,8);
    vector<int>*adj=g1.create_graph();
    g1.display();
    bipartite b1;

    bool ans=b1.isbarpatite(8,adj);
    cout<<"CHecking if the following graph is bipartite(0/1): "<<ans;

    return 0;
}