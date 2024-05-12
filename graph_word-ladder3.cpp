#include <bits/stdc++.h>

using namespace std;

class solution
{
    unordered_map<string, int> mpp;
    vector<vector<string>>ans;
    string b;
private:
    void dfs(string word, vector<string>&seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
        int sz= word.size();
        int steps= mpp[word];
        for (int i = 0; i < sz; i++)
            {
                char original = word[i];
                for (char x = 'a'; x <= 'z'; x++)
                {
                    word[i] = x;
                    if (mpp.find(word)!=mpp.end() && mpp[word]+1==steps)
                    {
                        seq.push_back(word);
                        dfs(word,seq);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }
    }
public:
    vector<vector<string>> word_ladder(string beginword, string endword, vector<string> &wordlist)
    {
        unordered_set<string> st(wordlist.begin(), wordlist.end());
        queue<string> q;
        q.push(beginword);
        mpp[beginword] = 1;
        b= beginword;
        int sz= beginword.size();
        st.erase(beginword);
        while (!q.empty())
        {
            string word = q.front();
            int steps = mpp[word];
            q.pop();
            if(word==endword)break;
            for (int i = 0; i < sz; i++)
            {
                char original = word[i];
                for (char x = 'a'; x <= 'z'; x++)
                {
                    word[i] = x;
                    if (st.count(word))
                    {
                        q.push(word);
                        mpp[word] = steps + 1;
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
            if (mpp.find(endword) != mpp.end())
            {
                vector<string>seq;
                seq.push_back(endword);
                dfs(endword,seq);
            }
        }
        return ans;
    }
};

int main(){

    vector<string>wordlist= {"hot","dot","dog","lot","log","cog"};
    string startword="hit";
    string target="cog";
    solution s1;
    vector<vector<string>> ans= s1.word_ladder(startword,target,wordlist);
    for(auto it: ans){
        for(auto itr: it){
            cout<<itr<<"->";
        }
        cout<<endl;
    }
    return 0; 
}