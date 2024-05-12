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

Node* insertobst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(data>root->data){
        root->right=insertobst(root->right,data);
    }else{
        root->left=insertobst(root->left,data);
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    while (data != -1)
    {
        root=insertobst(root,data);
        cin>>data;
    } 
}

// Method 1
bool findnode(Node* root,int data){
    if(root==NULL){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(data>root->data){
        return findnode(root->right,data);
    }else{
        return findnode(root->left,data);
    }
}

//Method 2
bool findnode2(Node* root,int data){
    Node* temp=root;
    while (temp!=NULL)
    {
        if(temp->data==data){
            return temp;
        }
        if(data>temp->data){
            temp=temp->right;
        }else{
            temp=temp->left;
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
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
    }
}

int main(){
    Node* root=NULL;
    takeinput(root);
    cout<<"\nPrinting the Binary Search Tree: "<<endl;
    levelordertraversal(root);
    bool ifnodexist=findnode(root,6);
    cout<<"\nIf the given node exit(1/0): "<<ifnodexist;
    ifnodexist=findnode2(root,9);
    cout<<"\nIf the given node exit(1/0){for 2nd method}: "<<ifnodexist;

    return 0;
}
