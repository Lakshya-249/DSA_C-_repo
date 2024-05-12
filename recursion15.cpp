#include<bits/stdc++.h>
#include<vector>
#include<string>

using namespace std;

class n_queen{
    public:
        bool issafe(int row, int col, vector<string>board, int n){
            int duprow=row;
            int dupcol=col;

            while (row >= 0 && col >= 0){
                if(board[row][col]=='Q') return false;
                row--;
                col--;
            }

            col=dupcol;
            row=duprow;

            while (col>=0){
                if(board[row][col]=='Q') return false;
                col--;
            }

            col=dupcol;
            row=duprow;

            while (row<n && col>=0){
                if(board[row][col]=='Q') return false;
                row++;
                col--;
            }

            return true;
        }
    public:
        void combination(int col,vector<vector<string>>&vec,vector<string>&board,int n){
            if (col==n){
                vec.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(issafe(row, col, board, n)){
                    board[row][col]='Q';
                    combination(col+1,vec,board,n);
                    board[row][col]='.';
                }
            }
        }

    public:
        vector<vector<string>> queen(int n){
            vector<vector<string>>vec;
            vector<string>board(n);
            string str(n,'.');
            for(int i=0;i<n;i++){
                board[i]=str;
            }
            combination(0,vec,board,n);
            return vec;
        }
};

int main(){
    n_queen q1;
    vector<vector<string>>vec=q1.queen(5);
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