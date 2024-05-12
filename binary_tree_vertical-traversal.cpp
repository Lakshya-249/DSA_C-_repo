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

        cout<<"Enter left node for "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

vector<int> verticaltraversal(Node* root){
    map<int,map<int,vector<int>>>mpp;
    queue<pair<Node*,pair<int,int>>>q;
    vector<int>ans;

    if(root==NULL){
        return ans;
    }
    q.push(make_pair(root,make_pair(0,0)));
    while (!q.empty())
    {
        pair<Node*,pair<int,int>>temp=q.front();
        q.pop();
        Node* firstnode=temp.first;
        int horzd=temp.second.first;
        int level=temp.second.second;
        mpp[horzd][level].push_back(firstnode->data);

        if(firstnode->left) q.push(make_pair(firstnode->left,make_pair(horzd-1,level+1)));
        if(firstnode->right) q.push(make_pair(firstnode->right,make_pair(horzd+1,level+1)));
    }
    for(auto itr1:mpp){
        for(auto itr2:itr1.second){
            for(auto itr3:itr2.second){
                ans.push_back(itr3);
            }
        }
    }
    return ans;    
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

int main(){
    Node* root=NULL;
    buildfromlevelorder(root);
    cout<<"\nPrinting the level order traversal-->\n";
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 8 -1 -1 -1...
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 -1 -1...
    levelordertraversal(root);
    vector<int>verticaltrv=verticaltraversal(root);
    cout<<"\nPrinting vertical traveral of the tree:--> ";
    for(auto itr:verticaltrv){
        cout<<itr<<" ";
    }
    
    return 0;
}