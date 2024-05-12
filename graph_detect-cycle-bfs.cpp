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
        bool detect(int src,vector<int>adj[],int vis[]){
            vis[src]=1;
            queue<pair<int,int>>q;
            q.push({src,-1});
            while(!q.empty()){
                int node= q.front().first;
                int parent= q.front().second;
                q.pop();

                for(auto adjnode: adj[node]){
                    if(!vis[adjnode]){
                        vis[adjnode]=1;
                        q.push({adjnode,node});
                    }else if(parent!=adjnode){
                        return true;
                    }
                }
            }
            return false;
        }
    public:
        bool detectcycle(int v,vector<int>adj[]){
            int vis[v+1]={0};
            for(int i=0;i<v+1;i++){
                if(!vis[i]){
                    if(detect(i,adj,vis)) return true;
                }
            }
            return false;
        }
};

int main(){
    graph g1(6,6);
    vector<int>*adj;
    adj= g1.creategraph();
    g1.display();
    cycle c1;
    bool ans= c1.detectcycle(6,adj);
    cout<<"Check whether the given list has cycle(0/1): "<<ans;

    return 0;
}