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
    public:
        vector<int> topsort(int v,vector<int>adj[]){
            int indegree[v+1]={0};
            for(int i=0;i<=v;i++){
                for(auto it: adj[i]){
                    indegree[it]++;
                }
            }
            queue<int>q;
            for(int i=0;i<=v;i++){
                if(indegree[i]==0){
                    q.push(i);
                }
            }

            vector<int>ans;
            while(!q.empty()){
                int node= q.front();
                q.pop();
                ans.push_back(node);

                for(auto it: adj[node]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
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