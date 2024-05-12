#include<bits/stdc++.h>

using namespace std;

class di_graph{
    private:
        int n,m;
        vector<int>*adj;
    public:
        di_graph(int a,int b){
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

class detect_cycle{
    private:
        bool dfscheck(int node,int vis[],int path[],vector<int>adj[]){
            vis[node]=1;
            path[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    if(dfscheck(it,vis,path,adj)) return true;
                }else if(path[it]){
                    return true;
                }
            }
            path[node]=0;
            return false;
        }
    public:
        bool iscycle(int v,vector<int>adj[]){
            int vis[v+1]= {0};
            int path[v+1]= {0};

            for(int i=0;i<v;i++){
                if(!vis[i]){
                    if(dfscheck(i,vis,path,adj)) return true;
                }
            }
            return false;
        }
};

int main(){
    di_graph g1(8,9);
    vector<int>*adj= g1.create_graph();
    g1.display();

    detect_cycle d1;
    int ans= d1.iscycle(8,adj);
    cout<<"The detection result for given graph is: "<<ans;

    return 0;
}