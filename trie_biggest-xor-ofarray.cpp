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
                int bit= (num>>i)&1;
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
                int bit= (num>>i)&1;
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

int max_xor(vector<int>arr1,vector<int>arr2){
    Trie t;
    for(auto itr: arr1)t.insert(itr);
    int maxi=0;
    for(auto itr: arr2){
        maxi=max(maxi,t.maxnum(itr));
    }
    return maxi;
}

int main(){
    vector<int>arr1={1,2,3,4,5,7};
    vector<int>arr2={6,8,9,1,2};
    int maxi=max_xor(arr1,arr2);
    cout<<"The maximum XOR of the 2 arrays: "<<maxi;

    return 0;
}