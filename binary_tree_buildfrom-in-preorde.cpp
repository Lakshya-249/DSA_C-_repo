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

Node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n,map<int,int>mpp){
    if(index>n || inorderstart>inorderend){
        return NULL;
    }

    int element=pre[index++];
    Node* root=new Node(element);
    int position=mpp[element];
    
    root->left=solve(in,pre,index,inorderstart,position-1,n,mpp);
    root->right=solve(in,pre,index,position+1,inorderend,n,mpp);

    return root;
}

Node* buildtree(int in[],int pre[],int n){
    int preindex=0;
    map<int,int>mpp;
    createmapping(in,mpp,n);
    Node* ans=solve(in,pre,preindex,0,n-1,n,mpp);
    return ans;
}

void postordertraversal(Node* root){
    if(root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    Node* tree= buildtree(in,pre,6);
    postordertraversal(tree);
    return 0;
}