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

class safe_states{
    private:
        bool dfscheck(int node,int vis[],int path[],int check[],vector<int>adj[]){
            vis[node]=1;
            path[node]=1;
            check[node]=0;
            for(auto it: adj[node]){
                if(!vis[it]){
                    if(dfscheck(it,vis,path,check,adj)){
                        check[node]=0;
                        return true;
                    }
                }else if(path[it]){
                    check[node]=0;
                    return true;
                }
            }
            path[node]=0;
            check[node]=1;
            return false;
        }
    public:
        vector<int> safenodes(int v,vector<int>adj[]){
            int vis[v+1]= {0};
            int check[v+1]={0};
            int path[v+1]={0};

            for(int i=0;i<v;i++){
                if(!vis[i]){
                    dfscheck(i,vis,path,check,adj);
                }
            }
            vector<int>safenode;
            for(int i=0;i<=v;i++){
                if(check[i]){
                    safenode.push_back(i);
                }
            }
            return safenode;
        }
};

int main(){
    di_graph g1(8,9);
    vector<int>*adj= g1.create_graph();
    g1.display();

    safe_states s1;
    vector<int>ans= s1.safenodes(8,adj);
    cout<<"\nThe safenodes for the given graph are: ";
    for(auto it: ans) cout<<it<<" ";

    return 0;
}