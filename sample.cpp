#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildtree(Node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting at left: " << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting at right: " << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void reverse_tree(Node *root){
    queue<Node *> q;
    stack<Node *>stq; 
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        stq.push(q.front());
        q.pop();
        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
    while(!stq.empty()){
        if(stq.top()==NULL){
            cout<<endl;
        }
        else{
            cout<<stq.top()->data<<" ";
        }
        stq.pop();
    }
}

int main()
{
    Node *root = NULL;
    root = buildtree(root);
    cout << "\nprinting the binary tree-->\n";
    //Data-->1 3 7 -1 -1 11 -1 -1 5 7 -1 -1 -1;
    levelordertraversal(root);
    reverse_tree(root);
    return 0;
}