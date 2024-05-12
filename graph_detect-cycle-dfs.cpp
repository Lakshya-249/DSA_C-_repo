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
        vector<int>* creategraph(){
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            return adj;
        }

        void display(){
            for(int i=0;i<m;i++){
                cout<<i<<": ";
                for(auto it: adj[i]) cout<<it<<" ";
                cout<<endl; 
            }
        }

        vector<int> bfs(){
            queue<int>q;
            int nd;
            int vis[n]={0};
            for(int i=0;i<m;i++){
                if(!adj[i].empty()){
                    nd=i;
                    break;
                }
            }
            q.push(nd);
            vis[nd]=1;
            vector<int>ans;
            while (!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
            return ans;
        }
};

class cycle{
    private:
        bool dfs(int node,int parent,int vis[],vector<int>adj[]){
            vis[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    if(dfs(it,node,vis,adj)) return true;
                }else if(it != parent) return true;
            }
            return false;
        }
    public:
        bool detectcycle(int v,vector<int>adj[]){
            int vis[v+1]= {0};
            for(int i=0;i<v+1;i++){
                if(!vis[i]){
                    if(dfs(i,-1,vis,adj)) return true;
                }
            }
            return false;
        }
};

int main(){
    graph g1(7,7);
    vector<int>*adj;
    adj= g1.creategraph();
    g1.display();
    cycle c1;
    bool ans= c1.detectcycle(7,adj);
    cout<<"Check whether the given list has cycle(0/1): "<<ans;

    return 0;
}