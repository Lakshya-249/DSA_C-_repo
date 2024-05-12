#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            this->data=val;
            this->left=NULL;
            this->right=NULL;
        }
};

Node* inserttoBST(Node* root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    if(root->data>data){
        root->left=inserttoBST(root->left,data);
    }else{
        root->right=inserttoBST(root->right,data);
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cout<<"Ente the data: ";
    cin>>data;
    while (data!=-1)
    {
        root=inserttoBST(root,data);
        cin>>data;
    }
}

void inordertraversal(Node* root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left,arr);
    arr.push_back(root->data);
    inordertraversal(root->right,arr);
}

void buildfrompreorder(Node* &root,vector<int>arr,int &index){
    if(root==NULL || index>=arr.size()){
        return;
    }
    root->data=arr[index++];
    buildfrompreorder(root->left,arr,index);
    buildfrompreorder(root->right,arr,index);
}

void BSTtoHeap(Node* &root){
    vector<int>arr;
    inordertraversal(root,arr);
    int index=0;
    buildfrompreorder(root,arr,index);
}

void levelordertraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){
    Node* root=NULL;
    takeinput(root);
    cout<<"Printing BST-->\n";
    levelordertraversal(root);
    BSTtoHeap(root);
    cout<<"Printing the heap-->\n";
    levelordertraversal(root);

    return 0;
}