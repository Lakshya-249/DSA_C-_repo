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
        vector<int>* create_graph(){
            cout<<"Enter the connected vertices: ";
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
                cout<<i<<" : {";
                for(auto it: adj[i]) cout<<it<<",";
                cout<<"}"<<endl;
            }
        }
};

class tarzan_algo{
    private:
        int timer=1;
        void dfs(int node,int parent,vector<int>adj[],
        vector<int>&vis,int low[],int tim[],vector<int>&mark){
            vis[node]=1;
            tim[node]=low[node]=timer;
            timer++;
            int child=0;
            for(auto it: adj[node]){
                if(it==parent) continue;
                if(vis[it]==0){
                    dfs(it,node,adj,vis,low,tim,mark);
                    low[node]= min(low[it],low[node]);
                    if(low[it]>=tim[node] && parent != -1){
                        mark[node]=1;
                    }
                    child++;
                }else{
                    low[node]= min(tim[it],low[node]);
                }
            }
            if(child>1) mark[node]=1;
        }
    public:
        vector<int> articulation_pt(vector<int>adj[],int v){
            vector<int>vis(v+1,0);
            int low[v+1];
            int tim[v+1];
            vector<int>mark(v+1,0);
            for(int i=0;i<v+1;i++){
                if(!vis[i]){
                    dfs(0,-1,adj,vis,low,tim,mark);
                }
            }   
            vector<int>ans;
            for(int i=0;i<v+1;i++){
                if(mark[i]==1) ans.push_back(i);
            }
            return ans;
        }
};

int main(){
    vector<int>*adj;
    graph g1(9,12);
    adj= g1.create_graph();
    g1.display();
    tarzan_algo tz1;
    vector<int>ans= tz1.articulation_pt(adj,12);
    cout<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }

    return 0;
}

// 0 1
// 1 2
// 2 0
// 1 3 
// 3 4
// 4 5
// 5 6
// 6 4
// 5 7
// 7 8
// 8 9
// 9 7