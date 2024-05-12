#include<bits/stdc++.h>

using namespace std;

class disjoint_set{
    public:
        vector<int>parent,size;
        disjoint_set(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }

        int findupar(int node){
            if(parent[node]==node) return node;
            return parent[node]= findupar(parent[node]);
        }

        void unionbysize(int u,int v){
            int node1= findupar(u);
            int node2= findupar(v);
            if(node1==node2) return;

            if(size[node1]<size[node2]){
                parent[node1]= node2;
                size[node2]+= size[node1];
            }else{
                parent[node2]= node1;
                size[node1]+= size[node2];
            }
        }
};

class solution{
    public:
        vector<vector<string>> account_merge(vector<vector<string>>arr){
            int n= arr.size();
            disjoint_set ds(n);
            unordered_map<string,int>mailtonode;
            for(int i=0;i<n;i++){
                for(int j=1;j<arr[i].size();j++){
                    string mail= arr[i][j];
                    if(mailtonode.find(mail)== mailtonode.end()){
                        mailtonode[mail]=i;
                    }else{
                        ds.unionbysize(i,mailtonode[mail]);
                    }
                }
            }
            vector<string>mergemail[n];
            for(auto it: mailtonode){
                string mail= it.first;
                int node= ds.findupar(it.second);
                mergemail[node].push_back(mail);
            }

            vector<vector<string>>ans;
            for(int i=0;i<n;i++){
                if(mergemail[i].size()==0) continue;
                sort(mergemail[i].begin(),mergemail[i].end());
                vector<string>temp;
                temp.push_back(arr[i][0]);
                for(auto it: mergemail[i]){
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }

            return ans;
        }
};

int main(){
    vector<vector<string>>arr={
        {"john","j1@com","j2@com","j3@com"},
        {"john","j4@com"},
        {"raj","r1@com","r2@com"},
        {"john","j1@com","j5@com"},
        {"raj","r2@com","r3@com"},
        {"mary","m1@com"}
    };
    solution s1;
    vector<vector<string>>ans= s1.account_merge(arr);
    for(auto it: ans){
        for(auto itr: it) cout<<itr<<" ";
        cout<<endl;
    }

    return 0;
}