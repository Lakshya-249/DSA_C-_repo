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

void findNode(Node* root,int n,Node* &ans){
    if(root==NULL){
        return;
    }
    if(root->data==n){
        ans=root;
    }
    findNode(root->left,n,ans);
    findNode(root->right,n,ans);
}

Node* solve(Node* root,Node* node1,Node* node2){
    // if(root==NULL){
    //     return NULL;
    // }
    // if(root->data>node1->data && root->data>node2->data){
    //     return solve(root->left,node1,node2);
    // }
    // if(root->data<node1->data && root->data<node2->data){
    //     return solve(root->right,node1,node2);
    // }
    // return root;

    //Method 2
    while(root!=NULL){
        if(root->data>node1->data && root->data>node2->data){
            root=root->left;
        }
        else if(root->data<node1->data && root->data<node2->data){
            root=root->right;
        }
        else{
            return root;
        }
    } 
}

Node* findLCA(Node* root,int n1,int n2){
    Node* node1;
    Node* node2;
    findNode(root,n1,node1);
    findNode(root,n2,node2);
    Node* ansroot=solve(root,node1,node2);
    return ansroot;
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
    int n1=11,n2=18;
    cout<<"The lowest common ancestor of "<<n1<<" and "<<n2<<": "<<findLCA(root,n1,n2)->data;
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1

    return 0;
}
