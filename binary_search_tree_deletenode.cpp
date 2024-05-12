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

int minval(Node* root){
    while(root->left!=NULL) root=root->left;
    return root->data;
}

Node* deletenode(Node* root,int data){
    if(root==NULL){
        return root;
    }
    if(root->data==data){
        // 0-child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1-child
            // left child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
            // right child
        if(root->left==NULL && root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        // 2-child;
        if(root->left!=NULL && root->right!=NULL){
            int mini= minval(root->right);
            root->data=mini;
            root->right=deletenode(root->right,mini);
            return root;        
        }
    }
    if(root->data>data){
        root->left=deletenode(root->left,data);
        return root;
    }else{
        root->right=deletenode(root->right,data);
        return root;
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
    Node* newroot=deletenode(root,15);
    cout<<"Printing the new BST after deleting the node: "<<endl;
    levelordertraversal(newroot);
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1

    return 0;
}
