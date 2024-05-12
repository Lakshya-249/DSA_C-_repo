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
            int value = this->data;
            if(this->next!=NULL){
                this->next = NULL;
                delete next;
            }
            cout<<"memory is free for node with value : "<<value<<endl;
        }
};

void insert_at_head(Node* &head,int dat){
    //creating new node;
    Node* temp = new Node(dat);
    temp->next = head;
    head=temp;
}

void insert_at_tail(Node* &tail,int dat){
    Node* temp = new Node(dat);
    tail->next=temp;
    tail=temp;
}

//RECURSIVE Approach...
void reverse_code(Node* &head,Node* &cur,Node* &prev){
    if(cur==NULL){
        head=prev;
        return;
    }
    Node* forward = cur->next;
    reverse_code(head,forward,cur);
    cur->next=prev;
}

Node* reverse(Node* &head){
    Node* cur=head;
    Node* prev=NULL;
    reverse_code(head,cur,prev);
    return head;
}

void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<endl;
    
    insert_at_head(head,15);
    insert_at_head(head,20);

    insert_at_tail(tail,35);
    insert_at_tail(tail,45);
    insert_at_tail(tail,50);
    insert_at_tail(tail,55);
    insert_at_tail(tail,60);
    insert_at_tail(tail,65);
    insert_at_tail(tail,70);
    insert_at_tail(tail,75); 

    print(head);
    cout<<endl;

    Node* nhead= reverse(head);
    print(nhead);

    return 0;
}
