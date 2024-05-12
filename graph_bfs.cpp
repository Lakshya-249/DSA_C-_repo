#include<bits/stdc++.h>

using namespace std;

class graph{
    int n,m;
    vector<int>*arr;
    public:
        graph(int a,int b): n(a),m(b) {
            arr=new vector<int>[n+1];
        }
        void make_graph(){
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                arr[u].push_back(v);
                arr[v].push_back(u);
            }
        }
        void display(){
            for(int i=0;i<n+1;i++){
                cout<<i<<": ";
                for(auto it:arr[i])cout<<it<<" ";
                cout<<endl;
            }
        }
        vector<int> bfstraversal(){
            int vis[n+1]={0}; //[0-max];
            vis[0]=1;
            queue<int>q;
            q.push(0);
            vector<int>bfs;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                bfs.push_back(node);
                for(auto it:arr[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push(it);
                    }
                }
            }
            return bfs;
        }
};

int main(){
    graph g1(5,6);
    g1.make_graph();
    g1.display();
    vector<int>bfs=g1.bfstraversal();
    for(auto it:bfs){
        cout<<it<<" ";
    }

    return 0;
}