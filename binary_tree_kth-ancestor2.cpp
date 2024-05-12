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

void solve(Node* root,int dat,vector<int>ans,int &result,int k){
    if(root==NULL){
        return;
    }
    ans.push_back(root->data);
    solve(root->left,dat,ans,result,k);
    solve(root->right,dat,ans,result,k);
    int size=ans.size()-1;
    if(root->data==dat){
        if(k>size || size<1) result=-1;
        else result=ans[size-k];
    }   
}

int kthAncestor(Node* root,int k,int dat){
    vector<int>ans;
    int result=0;
    solve(root,dat,ans,result,k);
    return result;
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
    //DATA-->1 2 3 4 5 6 -1 7 -1 -1 -1 -1 -1 8 -1 -1 -1...
    //DATA-->1 2 3 4 5 6 -1 7 -1 -1 -1 -1 -1 -1 -1...
    //DATA-->1 2 3 4 5 6 -1 -1 -1 7 -1 -1 8 -1 -1 -1 9 -1 -1...
    //DATA-->1 2 4 3 5 6 -1 -1 -1 -1 7 -1 -1 -1 -1...
    levelordertraversal(root);

    int ances=kthAncestor(root,2,6);
    cout<<"\nThe kth ancestor of the given node: "<<ances;
    
    return 0;
}