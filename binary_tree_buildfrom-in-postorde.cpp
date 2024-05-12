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

void createmapping(int in[],map<int,int>&mpp,int n){
    for(int i=0;i<n;i++){
        mpp[in[i]]=i;
    }
}

Node* solve(int in[],int post[],int &index,int inorderstart,int inorderend,int n,map<int,int>mpp){
    if(index<0 || inorderstart>inorderend){
        return NULL;
    }

    int element=post[index--];
    Node* root=new Node(element);
    int position=mpp[element];
    
    //In case of post order and inorder we first build right sub tree...
    root->right=solve(in,post,index,position+1,inorderend,n,mpp);
    root->left=solve(in,post,index,inorderstart,position-1,n,mpp);

    return root;
}

Node* buildtree(int in[],int post[],int n){
    int postindex=n-1;
    map<int,int>mpp;
    createmapping(in,mpp,n);
    Node* ans=solve(in,post,postindex,0,n-1,n,mpp);
    return ans;
}

void preordertraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}

int main(){
    int in[]={4,8,2,5,1,6,3,7};
    int post[]={8,4,5,2,6,7,3,1};
    Node* tree= buildtree(in,post,8);
    preordertraversal(tree);
    return 0;
}