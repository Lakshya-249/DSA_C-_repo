#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* random;
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->random=NULL;
        }
};

void insertatail(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail->random=temp;
        tail=temp;
    }
}

void reverse(Node* &head){
    if(head==NULL || head->random==NULL){
        return;
    }
    reverse(head->random);
    head->random->random=head;
    head->random=NULL;
}

void createrandompointers(Node* &head){
    Node* temp=head;
    reverse(head);
    temp->random=temp->next->next;
}

Node* clonelist(Node* &head){
    Node* temp=head;
    Node* clonehead=NULL;
    Node* clonetail=NULL;
    while (temp!=NULL)
    {
        insertatail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }
    Node* originalnode=head;
    Node* clonenode=clonehead;
    while (originalnode!=NULL || clonenode!=NULL)
    {
        Node* next=originalnode->next;
        originalnode->next=clonenode;
        originalnode=next;

        next=clonenode->next;
        clonenode->next=originalnode;
        clonenode=next;
    }
    temp=head;
    while (temp!=NULL)
    {
        if(temp->next!=NULL){
            temp->next->random=temp->random?temp->random->next:temp->random;
        }
        temp=temp->next->next;
    }
    originalnode=head;
    clonenode=clonehead;
    while (originalnode!=NULL || clonenode!=NULL)
    {
        originalnode->next=clonenode->next;
        originalnode=originalnode->next;

        if(originalnode!=NULL) clonenode->next=originalnode->next;
        clonenode=clonenode->next;
    }
     
    return clonehead;
}

void print(Node* head){
    if(head==NULL){
        cout<<"List is empty!!!";
        return;
    }
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    temp=head;
    cout<<"\nRandom pointers are : ";
    while (temp!=NULL)
    {
        cout<<temp->data<<"="<<temp->random->data<<endl;
        temp=temp->next;
    }
}

int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    insertatail(head,tail,2);
    insertatail(head,tail,3);
    insertatail(head,tail,4);
    insertatail(head,tail,5);
    insertatail(head,tail,6);
    insertatail(head,tail,7);
    insertatail(head,tail,8);
    insertatail(head,tail,9);
    insertatail(head,tail,10);
    insertatail(head,tail,11);
    
    createrandompointers(head);
    print(head);
    cout<<endl;

    Node* clone=clonelist(head);
    print(clone);

    return 0;
}