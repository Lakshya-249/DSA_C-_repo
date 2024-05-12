#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

void buildfromlevelorder(Node* &root){
    queue<Node*>q;
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new Node(data);
    q.push(root);

    while (!q.empty())
    {   
        Node* temp=q.front();
        q.pop();

        int leftdata;
        cout<<"\nEnter data for inserting at leftnode of data "<<temp->data<<": ";
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"\nEnter data for inserting at rightnode of data "<<temp->data<<": ";
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
}

void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        }else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    } 
}

vector<int> topview(Node* root){
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    q.push(make_pair(root,0));
    while (!q.empty())
    {
        pair<Node*,int>temp=q.front();
        q.pop();
        Node* node=temp.first;
        int horzd=temp.second;

        if(mpp.find(horzd)==mpp.end()){
            mpp[horzd]=node->data;
        }
        
        if(node->left) q.push(make_pair(node->left,horzd-1));
        if(node->right) q.push(make_pair(node->right,horzd+1));
    }
    for(auto itr:mpp){
        ans.push_back(itr.second);
    }
    return ans;
}

int main(){
    Node* root=NULL;
    buildfromlevelorder(root);
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 8 -1 -1 -1...
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 -1 -1...
    cout<<endl;
    levelordertraversal(root);
    cout<<"\nPrinting top view of the tree: ";
    vector<int>top=topview(root);
    for(auto itr:top){
        cout<<itr<<" ";
    }

    return 0;
}