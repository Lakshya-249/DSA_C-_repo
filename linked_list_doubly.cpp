#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
        ~Node(){
            int value = this->data;
            if(this->next!=NULL||this->prev!=NULL){
                this->next = NULL;
                this->prev = NULL;
                delete next;
                delete prev;
            }
            cout<<"memory is free for node with value : "<<value<<endl;
        }
};

void insert_at_head(Node* &head,int dat){
    Node* temp = new Node(dat);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void insert_at_tail(Node* &tail,int dat){
    Node* temp = new Node(dat);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

void insert_at_middle(Node* &head,Node* &tail,int pos,int dat){
    if(pos==1){
        insert_at_head(head,dat);
        return;
    }
    int ind=1;
    Node* temp = head;
    while(ind<pos-1){
        temp=temp->next;
        ind++;
    }
    if(temp->next==NULL||pos==-1){
        insert_at_tail(tail,dat);
        return;
    }
    Node* insertdata= new Node(dat);
    insertdata->next=temp->next;
    insertdata->prev=temp;
    temp->next->prev=insertdata;
    temp->next=insertdata;
}

void deletenode(Node* &head,Node* &tail,int pos){
    if(pos==1){
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
    }else{
        Node* cur=head;
        Node* prev=NULL;
        int ind=1;
        while(ind<pos){
            prev=cur;
            cur=cur->next;
            ind++;
        }
        if(cur->next==NULL){
            tail=prev;
        }
        prev->next=cur->next;
        cur->next->prev=prev;
        cur->next=NULL;
        cur->prev=NULL;
        delete cur;
    }
}

int nodelength(Node* &head){
    int len=0;
    Node* temp= head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<"DATA : "<<temp->data<<endl;
        cout<<"Previous node address : "<<temp->prev<<endl;
        cout<<"Next node address : "<<temp->next<<endl;
        temp=temp->next;
    }
}

int main(){
    Node* node1= new Node(10);
    Node* head= node1;
    Node* tail= node1;

    print(head);
    cout<<endl;

    insert_at_head(head,11);
    insert_at_head(head,12);
    insert_at_head(head,13);
    insert_at_head(head,14);

    insert_at_tail(tail,9);
    insert_at_tail(tail,8);
    insert_at_tail(tail,7);
    insert_at_tail(tail,6);
    insert_at_tail(tail,5);

    insert_at_middle(head,tail,3,16);
    insert_at_middle(head,tail,12,4);
    insert_at_middle(head,tail,-1,3);
    insert_at_middle(head,tail,5,20);

    deletenode(head,tail,3);

    print(head);
    cout<<"\nLenth of the linked List : "<<nodelength(head)<<endl;
    cout<<"tail : "<<tail->data<<endl;
    cout<<"head : "<<head->data;
    return 0;
}