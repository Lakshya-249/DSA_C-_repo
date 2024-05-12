#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~Node(){
            int value=this->data;
            if(this->next!=NULL){
                this->next=NULL;
                delete next;
            }else{
                delete next;
            }
            cout<<"The memory is freed for node with value: "<<value;
        }
};

void insertatail(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}

Node* findmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    Node* anshead=NULL;
    Node* anstail=NULL;
    while (left!=NULL && right!=NULL)
    {
        if(left->data<=right->data){
            insertatail(anshead,anstail,left->data);
            left=left->next;
        }else{
            insertatail(anshead,anstail,right->data);
            right=right->next;
        }
    }
    // while (left!=NULL)
    // {
    //     insertatail(anshead,anstail,left->data);
    //     left=left->next;
    // }
    // while (right!=NULL)
    // {
    //     insertatail(anshead,anstail,right->data);
    //     right=right->next;
    // }
    if(left!=NULL) anstail->next=left;
    else if(right!=NULL) anstail->next=right;
    return anshead;
}

Node* mergesort(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* mid=findmid(head);
    Node* left=head;
    Node* right=mid->next;
    mid->next=NULL;

    left=mergesort(left);
    right=mergesort(right);

    // Node* mergedlist=merge(left,right);
    // return mergedlist;
    return merge(left,right);
}

void print(Node* head){
    if(head==NULL){
        cout<<"List is empty...";
        return;
    }
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node* node1 = new Node(19);
    Node* head = node1;
    Node* tail = node1;

    insertatail(head,tail,20);
    insertatail(head,tail,10);
    insertatail(head,tail,13);
    insertatail(head,tail,15);
    insertatail(head,tail,24);
    insertatail(head,tail,16);
    insertatail(head,tail,17);
    insertatail(head,tail,30);
    insertatail(head,tail,27);
    insertatail(head,tail,22);
    
    print(head);
    cout<<endl;

    cout<<"After sorting the list-->\n";
    Node* sortlist=mergesort(head);
    print(sortlist);

    return 0;
}