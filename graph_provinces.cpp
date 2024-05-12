#include<bits/stdc++.h>

using namespace std;

class graph{
    private:
        int n,m;
        vector<int>*arr;
        void dfs(int node,int vis[]){
            vis[node]=1;
            for(auto it:arr[node]){
                if(!vis[it]){
                    dfs(it,vis);
                }
            }
        }
    public:
        graph(int n,int m){
            this->n=n;
            this->m=m;
            arr= new vector<int>[n+1];
        }
        void make_graph(){
            cout<<"Enter the data: ";
            for(int i=0;i<m;i++){
                int u,v;
                cin>>u>>v;
                arr[u].push_back(v);
                arr[v].push_back(u);
            }
        }
        int num_provinces(){
            int vis[n+1]={0};
            int node;
            int cnt=0;
            for(int i=0;i<n+1;i++){
                if(!arr[i].empty()){
                    node=i;
                    break;
                }
            }
            for(int i=node;i<n+1;i++){
                if(!vis[i]){
                    cnt++;
                    dfs(i,vis);
                }
            }
            return cnt;
        }
};

int main(){
    graph g1(8,5);
    g1.make_graph();
    cout<<"Number of provinces: "<<g1.num_provinces();

    return 0;
}