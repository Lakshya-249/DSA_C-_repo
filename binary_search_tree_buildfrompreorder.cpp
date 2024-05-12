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
    if(root->data>data){
        root->left=insertobst(root->left,data);
    }else{
        root->right=insertobst(root->right,data);
    }
    return root;
}

Node* takeinput(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    while (data!=-1)
    {
        root=insertobst(root,data);
        cin>>data;
    }  
}

Node* buildtree(vector<int>arr,int min,int max,int &ind){
    if(ind>=arr.size()){
        return NULL;
    }
    if(arr[ind]<min || arr[ind]>max){
        return NULL;
    } 
    Node* newroot=new Node(arr[ind++]);;
    newroot->left=buildtree(arr,min,newroot->data,ind);
    newroot->right=buildtree(arr,newroot->data,max,ind);
    return newroot;
}

Node* buildfrompreorder(vector<int>arr){
    int min=INT_MIN;
    int max=INT_MAX;
    int ind=0;
    return buildtree(arr,min,max,ind);
}

//Method 2
Node* buildtree2(vector<int>arr,int max,int &ind){
    if(ind>=arr.size()){
        return NULL;
    }
    if(arr[ind]>max){
        return NULL;
    } 
    Node* newroot=new Node(arr[ind++]);
    newroot->left=buildtree2(arr,newroot->data,ind);
    newroot->right=buildtree2(arr,max,ind);
    return newroot;
}

Node* buildfrompreorder2(vector<int>arr){
    
    int max=INT_MAX;
    int ind=0;
    return buildtree2(arr,max,ind);
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
    vector<int>arr={15 ,10 ,9 ,8 ,12 ,11 ,13 ,17 ,18 ,19 ,20 ,27};
    Node* root=buildfrompreorder(arr);
    levelordertraversal(root);
    cout<<endl;
    Node* root2=buildfrompreorder2(arr);
    levelordertraversal(root2);
}