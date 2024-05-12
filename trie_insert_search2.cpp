#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node* links[26];
    int endwith=0;
    int countpre=0;
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
        endwith++;
        flag=true;
    }

    bool isend(){
        return flag;
    }
};

class Trie{
    private:
        Node* root;
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
                node->countpre++;
            }
            node->setend();
        }

        void erase(string str){
            Node* node=root;
            for(int i=0;i<str.size();i++){
                node=node->get(str[i]);
                node->countpre--;
                node->endwith--;
            }
        }

        int startwith(string str){
            Node* node=root;
            for(int i=0;i<str.size();i++){
                if(node->containkey(str[i])){
                    node=node->get(str[i]);
                }else{
                    return 0;
                }
            }
            return node->countpre;
        }

        int countwords(string str){
            Node* node=root;
            for(int i=0;i<str.size();i++){
                if(node->containkey(str[i])){
                    node=node->get(str[i]);
                }else{
                    return 0;
                }
            }
            return node->endwith;
        }
};

int main(){
    Trie t;
    string arr[]={"apple","apple","apps","appy","appify"};
    int len=sizeof(arr)/sizeof(string);
    for(int i=0;i<len;i++){
        t.insert(arr[i]);
    }
    string word;
    cout<<"Enter the word to find: ";
    cin>>word;
    // int coun=t.startwith(word);
    int coun=t.countwords(word);
    cout<<"Number of words starting with "<<word<<": "<<coun;
    cout<<"\nEnter the word to erase: ";
    cin>>word;
    coun=t.countwords(word);
    cout<<"Number of "<<word<<" are: "<<coun;
    return 0;
}
