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
    if(root->data>data){
        root->left=insertobst(root->left,data);
    }else{
        root->right=insertobst(root->right,data);
    }
    return root;
}

Node* takeinput(Node* &root){
    int data;
    cout<<"Enter the Data: ";
    cin>>data;
    while (data!=-1)
    {
        root=insertobst(root,data);
        cin>>data;
    }
}

void inordertraversal(Node* root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    inordertraversal(root->left,arr);
    arr.push_back(root->data);
    inordertraversal(root->right,arr);
}

vector<int> mergearray(vector<int>arr1,vector<int>arr2){
    int size1=arr1.size();
    int size2=arr2.size();
    int i=0,j=0;
    vector<int>ans;
    while(i<size1 && j<size2){
        if(i<=j){
            ans.push_back(arr1[i]);
            i++;
        }else{
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while (i<size1)
    {
        ans.push_back(arr1[i]);
        i++;
    }
    while (j<size1)
    {
        ans.push_back(arr1[j]);
        j++;
    }
    return ans;
}

Node* solve(vector<int>arr,int i,int j){
    if(i>j){
        return NULL;
    }
    int mid=(i+j)/2;
    Node* newroot=new Node(arr[mid]);
    newroot->left=solve(arr,i,mid-1);
    newroot->right=solve(arr,mid+1,j);
    return newroot;
}

Node* merge2BST(Node* root1,Node* root2){
    vector<int>arr1,arr2;
    inordertraversal(root1,arr1);
    inordertraversal(root2,arr2);
    vector<int>ans=mergearray(arr1,arr2);
    int i=0,j=ans.size()-1;
    return solve(ans,i,j);
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
    Node* root1=NULL;
    takeinput(root1);
    cout<<"Printing the first BST-->\n";
    levelordertraversal(root1);

    Node* root2=NULL;
    takeinput(root2);
    cout<<"\nPrinting the second BST-->\n";
    levelordertraversal(root2);

    Node* mergedBST=merge2BST(root1,root2);
    cout<<"\nPrinting the merged BST of two BST-->\n";
    levelordertraversal(mergedBST);
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1
    //Data-->20 17 18 19 21 25 24 30 14 11 6 2 -1 

    return 0;
}