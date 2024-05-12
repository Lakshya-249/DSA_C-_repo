#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;

    bool containkey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch){
        links[ch-'a']=new Node();
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setend(){
        flag=true;
    }

    bool isend(){
        return flag;
    }
};

class Trie{
    private: Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(string str){
            Node* node=root;
            for(int i=0;i<str.size();i++){
                if(!node->containkey(str[i])){
                    node->put(str[i]);
                }
                node=node->get(str[i]);
            }
            node->setend();
        }

        bool checkprefixexist(string str){
            Node* node=root;
            for(int i=0;i<str.size();i++){
                if(node->containkey(str[i])){
                    node=node->get(str[i]);
                    if(node->isend()==false) return false;
                }
                else{
                    return false;
                }
            }
            return true;
        }
};

string findcompeletestr(vector<string>&vec){
    Trie t;
    for(auto itr:vec){
        t.insert(itr);
    }
    string longest="";
    for(auto itr:vec){
        if(t.checkprefixexist(itr)){
            if(itr.length()>longest.length()){
                longest=itr;
            }
            else if(itr.length()==longest.length() && itr<longest){
                longest=itr;
            }
        }
    }
    if(longest=="") return "None";
    return longest;
}

int main(){
    vector<string>vec={"n","ninja","nin","ni","ninj","ninga"};
    string findstr=findcompeletestr(vec);
    cout<<"The complete string is: "<<findstr;

    return 0;
}