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

void solve(Node* root,int &ans,int &k){
    if(root==NULL){
        return;
    }
    solve(root->left,ans,k);
    k--;
    if(k==0){
        ans=root->data;
    }
    solve(root->right,ans,k);
}

int kth_smallestnode(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    int ans=0;
    solve(root,ans,k);
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
    int result=kth_smallestnode(root,4);
    cout<<"Kth smallest node of the tree is: "<<result<<endl;
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1

    return 0;
}
