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

void lefttraversal(Node* root,vector<int>&ans){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    ans.push_back(root->data);
    if(root->left) lefttraversal(root->left,ans);
    else lefttraversal(root->right,ans);
}

void leaftraversal(Node* root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leaftraversal(root->left,ans);
    leaftraversal(root->right,ans);
}

void righttraversal(Node* root,vector<int>&ans){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    if(root->right) righttraversal(root->right,ans);
    else righttraversal(root->left,ans);
    ans.push_back(root->data);
}

vector<int> boundarytraversal(Node* root){
    vector<int>ans;
    ans.push_back(root->data);

    lefttraversal(root->left,ans);
    leaftraversal(root,ans);
    righttraversal(root->right,ans);

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
    //DATA-->3 2 1 -1 -1 -1 -1...
    levelordertraversal(root);

    cout<<"\nBoundary node are after traversing: ";
    vector<int>boundary=boundarytraversal(root);
    for(auto itr:boundary){
        cout<<itr<<" ";
    }
    
    return 0;
}