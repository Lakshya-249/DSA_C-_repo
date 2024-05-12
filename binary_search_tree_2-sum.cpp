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

bool find2sum(Node* root,int target){
    vector<int>vec;
    inordertraversal(root,vec);
    int i=0,j=vec.size()-1;
    while(i<j){
        int sum=vec[i]+vec[j];
        if(sum==target) return true;
        else if(sum>target){
            j--;
        }else{
            i++;
        }
    }
    return false;
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
    int target=16;
    cout<<"The sum of the target exits(1/0): "<<find2sum(root,target);
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1

    return 0;
}
