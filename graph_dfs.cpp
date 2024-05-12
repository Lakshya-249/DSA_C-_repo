#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<int>*arr;

        void dfs(vector<int>&ls,int vis[],int node){
            vis[node]=1;
            ls.push_back(node);
            for(auto it: arr[node]){
                if(!vis[it]){
                    dfs(ls,vis,it);
                }
            }
        } 
    public:
        graph(int a,int b): n(a),m(b){
            arr=new vector<int>[n+1];
        }
        void make_graph(){
            cout<<"enter the relations(a b): ";
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
                for(auto it: arr[i]) cout<<it<<" ";
                cout<<endl;
            }
        }

        vector<int> dfstraversal(){
            int vis[n+1]={0};
            vector<int>ls;
            int node;
            for(int i=0;i<n+1;i++){
                if(!arr[i].empty()){
                    node=i;
                    break;
                }
            }
            dfs(ls,vis,node);
            return ls;
        }
        ~graph(){
            delete []arr;
        }
};

int main(){
    graph g1(8,8);
    g1.make_graph();
    g1.display();
    vector<int>dfs=g1.dfstraversal();
    for(auto it: dfs) cout<<it<<" ";

    return 0;
}