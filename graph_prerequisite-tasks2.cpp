#include<bits/stdc++.h>

using namespace std;

class graph{
    public:
        vector<int> ispossible(int n,int m, vector<vector<int>>vec){
            vector<int>adj[n];
            for(auto it: vec){
                adj[it[1]].push_back(it[0]);
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

            vector<int>ans;
            while(!q.empty()){
                int node= q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node]){
                    indegree[it]--;
                    if(!indegree[it]) q.push(it);
                }
            }

            if(ans.size()==n) return ans;
            return {};
        }
};

int main(){
    graph g1;
    vector<vector<int>>vec={
        {1,0},
        {2,1},
        {3,2}
    };

    vector<int>ans= g1.ispossible(4,3,vec);
    cout<<"The oreder for completing tasks is: ";
    for(auto it: ans) cout<<it<<" ";
    
    return 0;
}