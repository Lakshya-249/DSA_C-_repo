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

Node* buildtree(Node* root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"\nEnter data for inserting at left-->"<<endl;
    root->left=buildtree(root->left);
    cout<<"\nEnter data for inserting at right-->"<<endl;
    root->right=buildtree(root->right);

    return root;
}

void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    while (!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

void inordertraversal(Node* root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}

int main(){
    Node* root=NULL;
    root=buildtree(root);
    // DATA-->1 3 7 -1 -1 11 -1 -1 5 7 -1 -1 -1...

    cout<<"\nPrinting the level_order_traversal-->\n";
    levelordertraversal(root);

    cout<<"\nPrinting the in_order_traversal-->\n";
    inordertraversal(root);

    return 0;
}