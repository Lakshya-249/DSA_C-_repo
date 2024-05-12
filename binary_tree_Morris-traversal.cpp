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

void morris_traversal(Node* root){
    Node* cur=root;
    Node* predc;
    while (cur!=NULL)
    {
        if(cur->left==NULL){
            cout<<cur->data<<" ";
            cur=cur->right;
        }else{
            predc = cur->left;
            while (predc->right != NULL && predc->right != cur) predc = predc->right;
            if(predc->right==NULL){
                predc->right=cur;
                cur=cur->left;
            }else{
                predc->right=NULL;
                cout<<cur->data<<" ";
                cur=cur->right;
            }
        }
    } 
}

void inordertraversal(Node* root){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
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

    cout<<"\nThe inorder traversal of the given tree: "<<endl;
    inordertraversal(root);

    cout<<"\nThe Morris traversal of the given tree: "<<endl;
    morris_traversal(root);
    
    return 0;
}