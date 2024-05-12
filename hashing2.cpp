#include<bits/stdc++.h>

using namespace std;

class solution{
    void findsum(vector<vector<int>>&fans,int target,vector<int>&table){
        for(int i=0;i<table.size();i++){
            for(int j=i+1;j<table.size();j++){
                int fsum=table[i]+table[j];
                int beg=j+1;
                int end=table.size()-1;
                while(beg<end){
                    int nsum=table[beg]+table[end];
                    if((fsum+nsum) == target){
                        vector<int>ans(4,0);
                        ans[0]= table[i];
                        ans[1]= table[j];
                        ans[2]= table[beg];
                        ans[3]= table[end];
                        fans.push_back(ans);
                        while (beg<end && table[beg]==ans[2]) ++beg;
                        while (beg<end && table[end]==ans[3]) --end;
                    }
                    else if ((fsum + nsum) < target) beg=beg+1;
                    else end=end-1;
                }
                while(j+1<table.size() && table[j+1]==table[j]) ++j;   
            }
            while(i+1<table.size() && table[i+1]==table[i]) ++i;
        }
    }
    public:
        vector<vector<int>> find4sum(vector<int>&table,int target){
            sort(table.begin(),table.end());
            vector<vector<int>>fans;
            findsum(fans,target,table);
            return fans;
        }
};

int main(){
    vector<int>table={3,2,1,10,5,9,7,8,6,4,4,3,11,6,18,13,10};
    solution s1;
    int a;
    cout<<"Enter a number : ";
    cin>>a;
    vector<vector<int>>ans=s1.find4sum(table,a);
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<4;j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}