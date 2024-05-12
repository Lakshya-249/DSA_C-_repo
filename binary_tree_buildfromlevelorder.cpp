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

void buildfromlevelorder(Node* &root){
    int data;
    queue<Node*>q;
    cout<<"Enter the data: ";
    cin>>data;
    root=new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left node for data: "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for data "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
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
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }  
}

int main(){
    Node* root=NULL;
    buildfromlevelorder(root);
    levelordertraversal(root);
    return 0;
}