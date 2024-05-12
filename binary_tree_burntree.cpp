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

void createmapping(int in[],map<int,int>&mpp,int n){
    for(int i=0;i<n;i++){
        mpp[in[i]]=i;
    }
}

Node* solve(int in[],int pre[],int &index,int inorderstart,int inorderend,int n,map<int,int>mpp){
    if(index>n || inorderstart>inorderend){
        return NULL;
    }

    int element=pre[index++];
    Node* root=new Node(element);
    int position=mpp[element];
    
    root->left=solve(in,pre,index,inorderstart,position-1,n,mpp);
    root->right=solve(in,pre,index,position+1,inorderend,n,mpp);

    return root;
}

Node* buildtree(int in[],int pre[],int n){
    int preindex=0;
    map<int,int>mpp;
    createmapping(in,mpp,n);
    Node* ans=solve(in,pre,preindex,0,n-1,n,mpp);
    return ans;
}

void postordertraversal(Node* root){
    if(root==NULL){
        return;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}

Node* nodetoparent(Node* root,int target,map<Node*,Node*>&mapping){
    Node* res=NULL;
    queue<Node*>q;
    q.push(root);
    mapping[root]=NULL;
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp->data==target){
            res=temp;
        }
        if(temp->left){
            mapping[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right){
            mapping[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return res;
}

int burningtree(Node* root,map<Node*,Node*>mapping){
    int ans=0;
    map<Node*,bool>visited;
    visited[root]=true;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {   
        bool flag=false;
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();

            if(temp->left && !visited[temp->left]){
                flag=true;
                visited[temp->left]=true;
                q.push(temp->left);
                cout<<temp->data<<" Node Burned the node with data "<<temp->left->data<<endl;
            }
            if(temp->right && !visited[temp->right]){
                flag=true;
                visited[temp->right]=true;
                q.push(temp->right);
                cout<<temp->data<<" Node Burned the node with data "<<temp->right->data<<endl;;
            }
            if(mapping[temp] && !visited[mapping[temp]]){
                flag=true;
                visited[mapping[temp]]=true;
                q.push(mapping[temp]);
                cout<<temp->data<<" Node Burned the node with data "<<mapping[temp]->data<<endl;
            }
        }
        if(flag==true){
            ans++;
        }
    }
    return ans;
    
}

int mintime(Node* root,int nodetoburn){
    map<Node*,Node*>mapping;
    Node* target=nodetoparent(root,nodetoburn,mapping);
    int ans=burningtree(target,mapping);
    return ans;
}

int main(){
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    Node* root= buildtree(in,pre,6);
    postordertraversal(root);
    cout<<endl;
    int time = mintime(root,5);
    cout<<"\nMinimum time to burn the tree: "<<time;
    return 0;
}