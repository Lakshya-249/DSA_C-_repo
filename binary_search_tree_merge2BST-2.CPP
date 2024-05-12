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

void takeinput(Node* &root){
    int data;
    cout<<"Enter the data: ";
    cin>>data;
    while (data!=-1)
    {
        root=insertobst(root,data);
        cin>>data;
    } 
}

void merge(Node* &root1,Node* &root2){
    Node* cur1=root1;
    Node* next1=cur1->right;
    Node* cur2=root2;
    Node* next2=cur2->right;

    if(cur1->data>cur2->data){
        cur2->right=cur1;
        cur1=cur2;
        next1=cur1->right;
        cur2=next2;
        root1=cur1;
    }
    while(next1!=NULL && cur2!=NULL){
        if(cur1->data<=cur2->data && cur2->data<=next1->data){
            cur1->right=cur2;
            next2=cur2->right;
            cur2->right=next1;
            cur1=cur2;
            cur2=next2;
        }
        else{
            cur1=next1;
            next1=next1->right;
            if(next1==NULL){
                cur1->right=cur2;
            }
        }
    }
}

void convertosortedDLL(Node* root,Node* &head){
    if(root==NULL){
        return;
    }
    convertosortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL) head->left=root;
    head=root;
    convertosortedDLL(root->left,head);
}

int countnode(Node* root){
    int count=0;
    while (root!=NULL)
    {
        count++;
        root=root->right;
    }
    return count;
}

Node* convertsortedDLLtoBST(Node* &head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    Node* left=convertsortedDLLtoBST(head,n/2);
    Node* root=head;
    root->left=left;
    head=head->right;
    root->right=convertsortedDLLtoBST(head,n-(n/2)-1);
    return root;
}

Node* merge2BST(Node* root1,Node* root2){
    Node* head1=NULL;
    Node* head2=NULL;
    convertosortedDLL(root1,head1);
    convertosortedDLL(root2,head2);
    merge(head1,head2);
    int n=countnode(head1);
    return convertsortedDLLtoBST(head1,n);
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

void printlist(Node* root){
    if(root==NULL){
        cout<<"List is empty...";
        return;
    }
    while(root!=NULL){
        cout<<root->data<<" ";
        root=root->right;
    }
}

int main(){
    Node* root1=NULL;
    takeinput(root1);
    levelordertraversal(root1);
    cout<<endl;
    Node* root2=NULL;
    takeinput(root2);
    levelordertraversal(root2);
    
    Node* BST= merge2BST(root1,root2);
    cout<<"\nPrinting the merged BST-->\n";
    levelordertraversal(BST);
    //Data-->15 10 12 11 13 17 18 19 20 27 9 8 -1 
    //Data-->20 17 18 19 21 25 24 30 14 11 6 2 -1

    return 0;
}