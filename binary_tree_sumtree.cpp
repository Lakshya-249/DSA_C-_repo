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

pair<bool,int> sumtree(Node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(1,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int>p=make_pair(1,root->data);
        return p;
    }
    pair<bool,int>left=sumtree(root->left);
    pair<bool,int>right=sumtree(root->right);
    pair<bool,int>ans;
    
    if(left.first && right.first && root->data==left.second+right.second){
        ans.first=1;
        ans.second=2*(root->data);
    }else{
        ans.first=0;
    }
    return ans;
}

bool issumtree(Node* root){
    pair<bool,int>ans=sumtree(root);
    return ans.first;
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
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 -1 -1...
    //DATA-->3 2 1 -1 -1 -1 -1...
    levelordertraversal(root);

    bool isumtree=issumtree(root);
    cout<<"\nThe given is tree is sumtree(0/1): "<<isumtree;
    
    return 0;
}