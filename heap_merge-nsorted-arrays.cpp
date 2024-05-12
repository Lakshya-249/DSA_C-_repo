#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        int row;
        int col;
        Node(int data,int row,int col){
            this->data=data;
            this->col=col;
            this->row=row;
        }
};

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

vector<int> merge_nsorted_arr(vector<vector<int>>arr,int n){
    priority_queue<Node*, vector<Node*>, compare>minh;
    vector<int>ans;
    for(int i=0;i<n;i++){
        Node* temp= new Node(arr[i][0],i,0);
        minh.push(temp);
    }
    while (!minh.empty())
    {
        Node* val=minh.top();
        ans.push_back(val->data);
        minh.pop();
        int x=val->row;
        int y=val->col;
        if(y+1<arr[x].size()){
            Node* next=new Node(arr[x][y+1],x,y+1);
            minh.push(next);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>>arr={
        {1, 2, 3},
        {2, 4, 6, 8},
        {10, 20, 30, 40, 50},
        {5, 10, 15, 20, 25, 30},
        {3, 6, 9, 12, 15, 18}
    };
    vector<int>ans=merge_nsorted_arr(arr,5);
    cout<<"PRINTING THE SORTED ARRAY-->\n";
    for(auto itr:ans) cout<<itr<<" ";
}