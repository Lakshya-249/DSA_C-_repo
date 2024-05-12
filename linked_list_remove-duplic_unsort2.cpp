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


//Appraoch 2...
void remove_duplicates(Node* &head){
    Node* cur=head;
    Node* prev=NULL;
    map<int,bool>mpp;
    mpp[cur->data]=true;
    while(cur->next!=NULL){
        prev=cur;
        cur=cur->next;
        if(mpp[cur->data]){
            prev->next=cur->next;
            Node* delnode=cur;
            delete delnode;
            cur=prev;
        }
        mpp[cur->data]=true;
    }
}

void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
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
    insert_at_tail(tail,9);
    insert_at_tail(tail,16);
    insert_at_tail(tail,13);
    insert_at_tail(tail,16);
    insert_at_tail(tail,27);
    insert_at_tail(tail,24);
    
    print(head);
    cout<<endl;

    remove_duplicates(head);
    print(head);

    return 0;
}
