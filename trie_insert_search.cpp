#include<bits/stdc++.h>
#include<string.h>

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
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }

        void insert(string str){
            Node* node=root;
            for(int i=0;i<str.length();i++){
                if(!node->containkey(str[i])){
                    node->put(str[i]);
                }
                node=node->get(str[i]);
            }
            node->setend();
        }

        bool searchword(string str){
            Node* node=root;
            for(int i=0;i<str.length();i++){
                if(!node->containkey(str[i])){
                    return false;
                }
                node=node->get(str[i]);
            }
            return node->isend();
        }
};

int main(){
    Trie t;
    string word[]={"john", "mary", "david", "sarah", "michael", "jennifer", "robert", "linda", "william", "patricia", 
                    "james", "elizabeth", "joseph", "susan", "charles", "jessica", "thomas", "karen", "daniel", "nancy", 
                    "matthew", "lisa", "christopher", "margaret", "andrew", "betty", "anthony", "dorothy", "mark", "sandra", 
                    "paul", "ashley", "donald", "emily", "george", "kimberly", "kenneth", "donna", "steven", "carol", 
                    "edward", "michelle", "brian", "emily", "ronald", "amanda", "timothy", "laura", "richard", "frank", 
                    "angela", "rebecca", "helen", "christine", "terry", "raymond", "joyce", "cheryl", "bruce", "arthur", 
                    "jane", "mildred", "melissa", "jason", "patrick", "pamela", "deborah", "larry", "kathleen", "cynthia", 
                    "jeffrey", "stephen", "rachel", "catherine", "brenda", "nicole", "rachel", "stephen", "barbara", "stephen", 
                    "betty", "caroline", "marie", "janice", "harold", "franklin", "diane", "benjamin", "margaret", "billy", 
                    "ruth", "gloria", "arthur", "ann", "douglas", "randy", "louise", "roger", "amy", "judith", "billy","jerry"
                };
    int len=sizeof(word)/sizeof(string);
    for(int i=0;i<len;i++){
        t.insert(word[i]);
    }
    string nword;
    cout<<"Finf the word: ";
    cin>>nword;
    bool exists=t.searchword(nword);
    cout<<"Does word exist(1/0): "<<exists<<endl;

    return 0;
}