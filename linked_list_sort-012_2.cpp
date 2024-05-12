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

void sortlist(Node* &head){
    Node* zeronode=new Node(-1);
    Node* head1=zeronode;
    Node* onenode=new Node(-1);
    Node* head2=onenode;
    Node* twonode=new Node(-1);
    Node* head3=twonode;

    Node* temp=head;
    while(temp!=NULL){
        int val=temp->data;
        if(val==0) insert_at_tail(head1,val);
        else if(val==1) insert_at_tail(head2,val);
        else if(val==2) insert_at_tail(head3,val);
        temp=temp->next;
    }
    head1->next=onenode->next;
    head2->next=twonode->next;
    head=zeronode->next;

    delete zeronode;
    delete onenode;
    delete twonode;
}

void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail,1);
    insert_at_tail(tail,2);
    insert_at_tail(tail,0);
    insert_at_tail(tail,2);
    insert_at_tail(tail,1);
    insert_at_tail(tail,2);
    insert_at_tail(tail,0);
    insert_at_tail(tail,1);
    insert_at_tail(tail,0);
    insert_at_tail(tail,2);
    
    print(head);
    cout<<endl;

    sortlist(head);
    print(head);

    return 0;
}
