#include<bits/stdc++.h>
#include<vector>

using namespace std;

class sudoko{
    public:
    bool issafe(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c) return false;
            if(board[row][i]==c) return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>&board){
        for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                if(board[row][col]=='.'){
                    for(char c='1';c<='9';c++){
                        if(issafe(board,row,col,c)){
                            board[row][col]=c;
                    
                            if(solve(board)){
                                return true;
                            }else{
                                board[row][col]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};


int main(){
    vector<vector<char>>board{
        {'.', '.', '.', '.', '1', '.', '.', '.', '.'},
        {'4', '.', '.', '.', '5', '.', '1', '.', '.'},
        {'.', '.', '2', '.', '.', '.', '.', '3', '.'},
        {'.', '7', '.', '3', '.', '4', '.', '.', '2'},
        {'.', '.', '.', '.', '7', '.', '.', '6', '.'},
        {'3', '.', '9', '.', '.', '.', '.', '.', '1'},
        {'.', '4', '.', '7', '.', '.', '.', '1', '.'},
        {'.', '.', '1', '.', '3', '.', '.', '.', '.'},
        {'7', '.', '.', '1', '.', '5', '.', '.', '.'}
    };
    
    sudoko sud;
    sud.solve(board);

    for(int x=0;x<9;x++){
        for(int y=0;y<9;y++){
            cout<<board[x][y]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}