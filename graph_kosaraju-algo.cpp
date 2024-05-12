#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<int>* adj;
    public:
        graph(int n,int m){
            this->n= n;
            this->m= m;
            adj= new vector<int>[n+1];
        }
        vector<int>* cretae_DAG(){
            cout<<"Enter the connected vertices: ";
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
            }
            return adj;
        }
        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<" : ";
                for(auto it: adj[i]) cout<<it<<" ";
                cout<<endl;
            }
        }
};

class kosaraju_algo{
    private:
        void dfs(int vis[],vector<int>adj[],int node,stack<int>&st){
            vis[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(vis,adj,it,st);
                }
            }
            st.push(node);
        }
        void dfs(int vis[],vector<int>adj[],int node){
            vis[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(vis,adj,it);
                }
            }
        }
    public:
        int strongly_connected_comp(vector<int>adj[],int v){
            int vis[v+1]={0};
            stack<int>st;
            for(int i=0;i<v+1;i++){
                if(!vis[i]){
                    dfs(vis,adj,i,st);
                }
            }
            vector<int>arr[v+1];
            for(int i=0;i<v+1;i++){
                for(auto it: adj[i]){
                    vis[it]=0;
                    arr[it].push_back(i);
                }
            }
            int cnt=0;
            while(!st.empty()){
                int node= st.top();
                st.pop();
                if(!vis[node]){
                    cnt++;
                    dfs(vis,arr,node);
                }
            }
            return cnt;
        }
};

int main(){
    vector<int>*adj;
    graph g1(7,10);
    adj= g1.cretae_DAG();
    g1.display();
    int ans;
    kosaraju_algo kg1;
    ans= kg1.strongly_connected_comp(adj,7);
    cout<<"The number of strongly connected components are: "<<ans;

    return 0;
}

// 0 2
// 2 1
// 1 0
// 2 3
// 3 4
// 4 7
// 4 5
// 5 6
// 6 4
// 6 7