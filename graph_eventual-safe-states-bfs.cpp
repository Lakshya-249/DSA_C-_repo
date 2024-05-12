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
    public:
        vector<int> safenodes(int v,vector<int>adj[]){
            vector<int>adjrev[v];
            for(int i=0;i<v;i++){
                for(auto it: adj[i]){
                    adjrev[it].push_back(i);
                }
            }
            int indegree[v]={0};
            for(int i=0;i<v;i++){
                for(auto it: adjrev[i]){
                    indegree[it]++;
                }
            }

            queue<int>q;
            for(int i=0;i<v;i++){
                if(!indegree[i]) q.push(i);
            }
            vector<int>ans;
            while(!q.empty()){
                int node= q.front();
                q.pop();
                ans.push_back(node);

                for(auto it: adjrev[node]){
                    indegree[it]--;
                    if(!indegree[it]) q.push(it);
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
        }
};

int main(){
    di_graph g1(9,9);
    vector<int>*adj= g1.create_graph();
    g1.display();

    safe_states s1;
    vector<int>ans= s1.safenodes(9,adj);
    cout<<"\n The safe states in the gien graph are: ";
    for(auto it: ans) cout<<it<<" ";

    return 0;
}