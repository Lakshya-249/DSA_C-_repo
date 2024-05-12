#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
    bool ispossible(int n,vector<pair<int,int>>vec){
        vector<int>adj[n];
        for(auto it: vec){
            adj[it.first].push_back(it.second);
        }

        int indegree[n]={0};
        for(int i=0;i<n;i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indegree[i]) q.push(i);
        }

        int cnt=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;

            for(auto it: adj[node]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        if(cnt==n) return true;
        return false;
    }
};

int main(){
    graph g1;
    vector<pair<int,int>>vec={
        {1,0},
        {2,1},
        {3,2}
    };

    bool ans= g1.ispossible(4,vec);
    cout<<"Checking whether tasks can be completed(1/0): "<<ans;

    return 0;
}