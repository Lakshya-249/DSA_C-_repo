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

class topological_sort{
    private:
        void dfs(int node,int vis[],stack<int>&st,vector<int>adj[]){
            vis[node]=1;
            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it,vis,st,adj);
                }
            }
            st.push(node);
        }
        
    public:
        vector<int> topsort(int v,vector<int>adj[]){
            int vis[v+1]={0};
            stack<int>st;
            for(int i=0;i<=v;i++){
                if(!vis[i]){
                    dfs(i,vis,st,adj);
                }
            }
            vector<int>ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }
};

int main(){
    di_graph g1(5,6);
    vector<int>*adj=g1.create_graph();
    g1.display();

    topological_sort t1;
    vector<int>ans= t1.topsort(5,adj);
    cout<<"\nThe topological sort for the above directed acyclic graph: ";
    for(auto it: ans) cout<<it<<" ";

    return 0;
    
}
