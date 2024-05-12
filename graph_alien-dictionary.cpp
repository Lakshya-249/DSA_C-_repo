#include<bits/stdc++.h>

using namespace std;

class graph{
    private: 
        vector<int> toposort(int v,vector<int>adj[]){
            int indegree[v]={0};
            for(int i=0;i<v;i++){
                for(auto it: adj[i]){
                    indegree[it]++;
                }
            }

            queue<int>q;
            for(int i=0;i<v;i++){
                if(!indegree[i]) q.push(i);
            }

            vector<int>ans;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it: adj[node]){
                    indegree[it]--;
                    if(!indegree[it]) q.push(it);
                }
            }
            return ans;
        }
    public:
        string findorder(string dict[],int n,int k){
            vector<int>adj[k];
            for(int i=0;i<n-1;i++){
                string s1= dict[i];
                string s2= dict[i+1];
                int len= min(s1.length(),s2.length());
                for(int j=0;j<len;j++){
                    if(s1[j]!=s2[j]){
                        adj[s1[j]-'a'].push_back(s2[j]-'a');
                        break;
                    }
                }
            }

            vector<int>topsort= toposort(k,adj);
            string ans="";
            for(auto it: topsort){
                ans+= char(it+'a');
            }
            return ans;
        }
};

int main(){
    graph g1;
    string dict[]= {"baa","abcd","abca","cab","cad"};
    string ans= g1.findorder(dict,5,4);
    cout<<"The alien dictionary is: "<<ans;

    return 0;
}