#include<bits/stdc++.h>

using namespace std;

int solution(string startword,string targetword,vector<string>& wordlist){
    unordered_set<string>st;
    for(auto it: wordlist){
        st.insert(it);
    }

    queue<pair<string,int>>q;

    q.push({startword,1});
    while(!q.empty()){
        string word= q.front().first;
        int steps= q.front().second;
        q.pop();
        if(word==targetword) return steps;
        for(int i=0;i<word.size();i++){
            char original= word[i];
            for(char x='a';x<='z';x++){
                word[i]= x;
                if(st.find(word)!=st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
            word[i]=original;
        }
    }
    return -1;
}

int main(){
    vector<string>wordlist= {"hot","dot","dog","lot","log","cog"};
    string startword="hit";
    string target="cog";
    int ans= solution(startword,target,wordlist);
    cout<<"The numbers steps required for the given wordlist: "<<ans;

    return 0; 
}