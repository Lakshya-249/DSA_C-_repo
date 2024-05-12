#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> wordladder(string startword, string endword,vector<string>& wordlist){
    queue<vector<string>>q;
    q.push({startword});
    vector<string>onlevel;
    int level=0;
    onlevel.push_back(startword);
    unordered_set<string>st;
    for(auto it: wordlist){
        st.insert(it);
    }
    vector<vector<string>>ans;
    while(!q.empty()){
        vector<string>arr= q.front();
        q.pop();
        string word= arr.back();
        if(arr.size()>level){
            level++;
            for(auto it: onlevel){
                st.erase(it);
            }
        }

        if(word==endword){
            if(ans.size()==0){
                ans.push_back(arr);
            }else if(ans[0].size()==arr.size()){
                ans.push_back(arr);
            }
        }

        for(int i=0;i<word.size();i++){
            char original= word[i];
            for(char x='a';x<='z';x++){
                word[i]=x;
                if(st.find(word)!=st.end()){
                    arr.push_back(word);
                    onlevel.push_back(word);
                    q.push(arr);
                    arr.pop_back();
                }
            }
            word[i]=original;
        }
    }
    return ans;
}

int main(){
    vector<string>wordlist= {"hot","dot","dog","lot","log","cog"};
    string startword="hit";
    string target="cog";
    vector<vector<string>> ans= wordladder(startword,target,wordlist);
    for(auto it: ans){
        for(auto itr: it){
            cout<<itr<<"->";
        }
        cout<<endl;
    }
    return 0; 
}