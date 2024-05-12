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

void insert_at_tail(Node* &tail,int dat){
    Node* temp = new Node(dat);
    tail->next=temp;
    tail=temp;
}


Node* return_halfs(Node* &head){
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast->next!=NULL) fast=fast->next;
    }
    Node* temp=slow->next;
    fast->next=slow->next;
    slow->next=head;
    return temp;
}

void print(Node* head){
    Node* temp = head;
    do{
        cout<<head->data<<" ";
        head=head->next;
    }while(head!=temp && head!=NULL);
}

int main(){
    Node* node1 = new Node(9);
    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail,20);
    insert_at_tail(tail,10);
    insert_at_tail(tail,13);
    insert_at_tail(tail,15);
    insert_at_tail(tail,24);
    insert_at_tail(tail,16);
    insert_at_tail(tail,13);
    insert_at_tail(tail,16);
    insert_at_tail(tail,27);
    insert_at_tail(tail,24);
    
    print(head);
    cout<<endl;

    Node* shalf=return_halfs(head);
    print(shalf);
    cout<<endl;

    print(head);

    return 0;
}
