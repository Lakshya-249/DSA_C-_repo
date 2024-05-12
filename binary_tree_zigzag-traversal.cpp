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

vector<int>  zigzagtraversal(Node* root){
    vector<int>result;
    if(root==NULL){
        return result;
    }
    queue<Node*>q;
    q.push(root);
    bool lefttoright=true;
    while (!q.empty())
    {
        int size=q.size();
        vector<int>ans(size);
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            int index=lefttoright?i:size-i-1;
            ans[index]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        for(auto x:ans){
            result.push_back(x);
        }
        lefttoright=!lefttoright;
    }
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
    //DATA-->1 2 3 4 5 6-1 7 -1 -1 -1 -1 -1 -1 -1...
    //DATA-->3 2 1 -1 -1 -1 -1...
    levelordertraversal(root);

    cout<<"\nPrinting zig-zag traversing: ";
    vector<int>zigzag=zigzagtraversal(root);
    for(auto itr:zigzag){
        cout<<itr<<" ";
    }
    
    return 0;
}