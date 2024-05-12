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

pair<int,int> find_succ_predc(Node* root,int data){
    Node* temp=root;
    int succ=-1;
    int predc=-1;
    while (temp->data!=data)
    {
        if(temp->data>data){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            predc=temp->data;
            temp=temp->right;
        }
    }
    Node* leftree=temp->left;
    while (leftree!=NULL)
    {
      predc=leftree->data;
      leftree=leftree->right;  
    }

    Node* rightree=temp->right;
    while (rightree!=NULL)
    {
        succ=rightree->data;
        rightree=rightree->left;
    }
    pair<int,int>ans=make_pair(predc,succ);
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
    pair<int,int>ans=find_succ_predc(root,9);
    cout<<"Predecessor of the node: "<<ans.first<<"\nSuccessor of the node: "<<ans.second;
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1

    return 0;
}
