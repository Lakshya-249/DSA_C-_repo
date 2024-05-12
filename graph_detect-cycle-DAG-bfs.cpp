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
    bool detect_cycle(int v,vector<int>adj[]){
        int indegree[v+1]={0};
        for(int i=0;i<=v;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<=v;i++){
            if(!indegree[i]) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        if(cnt == v+1) return false;
        return true;
    }
};

int main(){
    di_graph g1(5,6);
    vector<int>*adj=g1.create_graph();
    g1.display();

    topological_sort t1;
    bool ans= t1.detect_cycle(5,adj);
    cout<<"\nThe detection of cycle in above graph(0/1): "<<ans;

    return 0;
}