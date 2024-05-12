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

pair<bool,int> treebalanced(Node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(1,0);
        return p;
    }
    pair<bool,int>left=treebalanced(root->left);
    pair<bool,int>right=treebalanced(root->right);

    bool opt1=left.first;
    bool opt2=right.first;
    bool opt3=abs(left.second - right.second)<=1;

    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;
    if(opt1 && opt2 && opt3){
        ans.first=1;
    }else{
        ans.first=0;
    }
    return ans;
}

bool istreebalanced(Node* root){
    pair<bool,int>ans=treebalanced(root);
    return ans.first;
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
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 8 -1 -1 -1...
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 -1 -1...
    levelordertraversal(root);
    int heightoftree=height(root);
    cout<<"\nHeight of the tree: "<<heightoftree;
    bool balance=istreebalanced(root);
    cout<<"\nTree is balanced(0/1): "<<balance;
    return 0;
}