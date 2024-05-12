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

Node* insertdata(Node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"leftdata of node "<<root->data<<": ";
    root->left=insertdata(root->left);
    cout<<"rightdata of node "<<root->data<<": ";
    root->right=insertdata(root->right);
    return root;
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

int countnode(Node* root){
    if(root==NULL){
        return 0;
    }
    int ans=1+countnode(root->left)+countnode(root->right);
    return ans;
}

bool isCBT(Node* root,int ind,int totalnode){
    if(root==NULL){
        return true;
    }
    if(ind>=totalnode){
        return false;
    }
    else{
        bool left =isCBT(root->left,2*ind+1,totalnode);
        bool right =isCBT(root->right,2*ind+2,totalnode);
        return left && right;
    }
}

bool ismaxheap(Node* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    if(root->right==NULL){
        return root->data>root->left->data;
    }
    else{
        bool left = ismaxheap(root->left);
        bool right = ismaxheap(root->right);
        if(left && right && (root->data>root->left->data && root->data>root->right->data)){
            return true;
        }else{
            return false;
        }
    }
}

bool isheap(Node* root){
    int index=0;
    int totalnode=countnode(root);
    if(isCBT(root,index,totalnode) && ismaxheap(root)){
        return true;
    }else{
        return false;
    }
}

int main(){
    Node* root=NULL;
    root=insertdata(root);
    cout<<"Printing the binary tree-->\n";
    levelordertraversal(root);
    cout<<"\nChecking the binary tree is heap(1/0): "<<isheap(root);
    
    return 0;
}