#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* links[2];
    bool containkey(int n){
        return links[n]!=NULL;
    }
    void put(int n){
        links[n]=new Node();
    }
    Node* get(int n){
        return links[n];
    }
};

class Trie{
    private: Node* root;
    public:
        Trie(){
            root=new Node();
        }

        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(!node->containkey(bit)){
                    node->put(bit);
                }
                node=node->get(bit);
            }
        }

        int maxnum(int num){
            Node* node=root;
            int maxnum=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containkey(1-bit)){
                    maxnum = maxnum|(1<<i);
                    node=node->get(1-bit);
                }else{
                    node=node->get(bit);
                }
            }
            return maxnum;
        }
};

vector<int> max_xor_queries(vector<int>arr,vector<vector<int>>queries){
    sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>>oq;
    int size=queries.size();
    for(int i=0;i<size;i++){
        oq.push_back({queries[i][1],{queries[i][0],i}});
    }
    sort(oq.begin(),oq.end());
    int ind=0;
    vector<int>ans(size,0);
    int n=arr.size();
    Trie t;
    for(int i=0;i<size;i++){
        int ai=oq[i].first;
        int xi=oq[i].second.first;
        int qind=oq[i].second.second;
        while (ind<n && arr[ind]<=ai)
        {
            t.insert(arr[ind]);
            ind++;
        }
        if(ind==0) ans[qind]=-1;
        else ans[qind]= t.maxnum(xi);
    }
    return ans;
}

int main(){
    vector<int>arr={1,3,2,5,4,6,7};
    vector<vector<int>>queries={
        {3,6},
        {5,2},
        {2,5},
        {3,1}
    };
    vector<int>ans=max_xor_queries(arr,queries);
    cout<<"Anwers of the following queries are: ";
    for(auto itr:ans)cout<<itr<<" ";
    // cout<<(3^7);
    return 0;
}