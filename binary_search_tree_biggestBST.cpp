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

class info{
    public:
        int max;
        int min;
        bool isBST;
        int size;
};

Node* insertobst(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=insertobst(root->left,data);
    }else{
        root->right=insertobst(root->right,data);
    }
    return root;
}

info solve(Node* root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};
    }
    info left=solve(root->left,ans);
    info right=solve(root->right,ans);

    info curnode;
    curnode.size= left.size + right.size + 1;
    curnode.min=min(root->data,left.min);
    curnode.max=max(root->data,right.max);

    if((left.isBST && right.isBST) && (root->data>left.max && root->data<right.min)){
        curnode.isBST=true;
    }else{
        curnode.isBST=false;
    }
    if(curnode.isBST){
        ans=max(ans,curnode.size);
    }
    return curnode;
}

int biggestBST(Node* root){
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}

void takeinput(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    while (data!=-1)
    {
        root=insertobst(root,data);
        cin>>data;
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

int main(){
    Node* root=NULL;
    takeinput(root);
    levelordertraversal(root);
    cout<<"\nLength of the biggest BST: "<<biggestBST(root);
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1 
    //Data-->20 17 18 19 21 25 24 30 14 11 6 2 -1

    return 0;
}