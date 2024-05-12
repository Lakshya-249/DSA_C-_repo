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

void inordertraversal(Node* root,vector<int>&vec){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left,vec);
    vec.push_back(root->data);
    inordertraversal(root->right,vec);
}

Node* balancetree(int i,int j,vector<int>&vec){
    if(i>j){
        return NULL;
    }
    int mid=(i+j)/2;
    Node* newroot=new Node(vec[mid]);
    newroot->left=balancetree(i,mid-1,vec);
    newroot->right=balancetree(mid+1,j,vec);
    return newroot;
}

Node* balancethetree(Node* root){
    vector<int>vec;
    inordertraversal(root,vec);
    int i=0,j=vec.size()-1;
    return balancetree(i,j,vec);
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
    Node* newroot= balancethetree(root);
    cout<<"Printing the balanced tree:->\n";
    levelordertraversal(newroot);
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1

    return 0;
}
