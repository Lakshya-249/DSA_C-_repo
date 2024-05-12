#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node* links[26];
    bool containkey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch){
        links[ch-'a']=new Node();
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

int count_distinct_substring(string word){
    int cnt=0;
    Node* root=new Node();
    for(int i=0;i<word.size();i++){
        Node* node=root;
        for(int j=i;j<word.size();j++){
            if(!node->containkey(word[j])){
                cnt++;
                node->put(word[i]);
            }
            node=node->get(word[i]);
        }
    }
    return cnt+1;
}

int main(){
    string word="abab";
    int cont=count_distinct_substring(word);
    cout<<"Number of Distinct Substring: "<<cont;

    return 0;
}