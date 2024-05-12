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

void insert_at_middle(Node* &head,Node* &tail,int pos,int dat){
    if(pos==1){
        insert_at_head(head,dat);
        return;
    }
    if(pos==-1){
        insert_at_tail(tail,dat);
        return;
    }
    int ind=1;
    Node* temp = head;
    while(ind<pos-1){
        temp = temp->next;
        ind++;
    }
    if(temp->next==NULL){
        insert_at_tail(tail,dat);
        return;
    }
    Node* insertdata = new Node(dat);
    insertdata->next=temp->next;
    temp->next=insertdata;
}

void delete_node(Node* &head,Node* &tail,int pos){
    int ind=1;
    Node* temp=head;
    if(pos==1){
        head=temp->next;
        // temp->next=NULL;
        delete temp;
    }
    else{
        while(ind<pos-1){
            temp=temp->next;
            ind++;
        }
        Node* temp2= temp->next;
        if(temp2->next==NULL){
            tail=temp;
        }
        temp->next=temp2->next;
        // temp2->next=NULL;
        delete temp2;
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
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout<<endl;
    
    insert_at_head(head,15);
    insert_at_head(head,20);

    insert_at_tail(tail,35);
    insert_at_tail(tail,40);

    insert_at_middle(head,tail,3,25);
    insert_at_middle(head,tail,1,30);
    insert_at_middle(head,tail,8,50);
    insert_at_middle(head,tail,-1,60);

    insert_at_tail(tail,65);
    print(head);
    cout<<endl;

    delete_node(head,tail,3);
    delete_node(head,tail,5);
    delete_node(head,tail,1);
    delete_node(head,tail,7);


    print(head);
    cout<<"\n tail: "<<tail->data;
    return 0;
}
