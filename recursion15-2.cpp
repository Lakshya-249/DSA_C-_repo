#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

class n_queen{
    public:
        void combination(int col,vector<vector<string>>&ans,vector<string>&board,
        vector<int>&leftrow,vector<int>&upperdiagonal,vector<int>&lowerdiagonal,int n){
            if(col==n){
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1 + col-row]==0){
                    leftrow[row]=1;
                    lowerdiagonal[row+col]=1;
                    upperdiagonal[n-1 + col-row]=1;
                    board[row][col]='Q';
                    combination(col+1,ans,board,leftrow,upperdiagonal,lowerdiagonal,n);
                    leftrow[row]=0;
                    upperdiagonal[n-1 + col-row]=0;
                    lowerdiagonal[row+col]=0;
                    board[row][col]='.';
                }
            }
        }
    public:
        public:
        vector<vector<string>> queen(int n){
            vector<vector<string>>ans;
            vector<string>board(n);
            string str(n,'.');
            for(int i=0;i<n;i++){
                board[i]=str;
            }
            vector<int>leftrow(n,0) , lowerdiagonal(2*n -1,0), upperdiagonal(2*n -1,0);
            combination(0,ans,board,leftrow,upperdiagonal,lowerdiagonal,n);
            return ans;
        }
};

int main(){
    n_queen q1;
    vector<vector<string>>vec=q1.queen(4);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            for(int k=0;k<vec[i][j].size();k++){
                cout<<vec[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}