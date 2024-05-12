#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        int row,col;
        Node(int data,int r,int c){
            this->data=data;
            this->row=r;
            this->col=c;
        }
};

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

int ksorted_smallestrange(vector<vector<int>>arr,int k){
    int mini=INT_MAX;
    int maxi=INT_MIN;
    priority_queue<Node*,vector<Node*>,compare>minh;
    for(int i=0;i<k;i++){
        int element=arr[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minh.push(new Node(element,i,0));
    }

    int start=mini,end=maxi;
    
    while (!minh.empty())
    {
        Node* temp=minh.top();
        minh.pop();
        mini=temp->data;
        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }
        if(temp->col+1<arr[temp->row].size()){
            maxi=max(maxi,arr[temp->row][temp->col+1]);
            minh.push(new Node(arr[temp->row][temp->col+1],temp->row,temp->col+1));
        }
        else{
            break;
        }
    }
    return end-start;
}

int main(){
    vector<vector<int>>arr{
        {1, 2, 7},
        {4, 6, 8},
        {5, 10, 15}
    };
    int ans=ksorted_smallestrange(arr,3);
    cout<<"Smallest range for following 3 arrays is: "<<ans;

    return 0;
}