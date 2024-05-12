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
    queue<Node*>q;
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    root=new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<": ";
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<": ";
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

bool aretreeidentical(Node* node1,Node* node2){
    if(node1==NULL && node2==NULL){
        return true;
    }
    else if(node1==NULL || node2==NULL) return false;
    else if(node1->data!=node2->data){
        return false;
    }
    bool temp1=aretreeidentical(node1->left,node2->left);
    bool temp2=aretreeidentical(node1->right,node2->right);
    if(temp1 && temp2){
        return true;
    }else return false;
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
    cout<<"\nPrinting the level order traversal-->\n";
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 -1 -1...
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 8 -1 -1 -1...
    levelordertraversal(root);
    Node* root2=NULL;
    buildfromlevelorder(root2);
    cout<<"\nPrinting the level order traversal-->\n";
    levelordertraversal(root2);

    bool identical=aretreeidentical(root,root2);
    cout<<"\nTrees are identical(0/1): "<<identical;
    return 0;
}