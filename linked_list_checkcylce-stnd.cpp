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
};

void inserttail(Node* &tail,int data){
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp;
}

bool floyedDetectloop(Node* head){
    Node* slow= head;
    Node* fast= head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

void make_a_loop(Node* &head,Node* &tail){
    int ind=1;
    Node* temp=head;
    while(ind!=5){
        temp=temp->next;
        ind++;
    }
    tail->next=temp;
}

Node* getstartingnode(Node* head){
    Node* slow=head;
    Node* fast=head;
    do{
        fast=fast->next->next;
        slow=slow->next;
    }while(fast!=slow);
    slow=head;
    while(fast!=slow){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

void removecycle(Node* &head){
    Node* temp=getstartingnode(head);
    Node* temp2=temp;
    while(temp2->next!=temp){
        temp2=temp2->next;
    }
    temp2->next=NULL;
}

void print(Node* tail){
    Node* temp =tail;
    if(tail==NULL){
        cout<<"List is empty...";
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp && tail!=NULL);
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    inserttail(tail,35);
    inserttail(tail,45);
    inserttail(tail,50);
    inserttail(tail,55);
    inserttail(tail,60);
    inserttail(tail,65);
    inserttail(tail,70);
    inserttail(tail,75);

    print(head);
    cout<<"\nList is circular/not : "<<floyedDetectloop(head);

    make_a_loop(head,tail);
    cout<<"\nList is circular/not : "<<floyedDetectloop(head);
    // print(head);

    Node* check=getstartingnode(head);
    cout<<"\nStarting cycle node : "<<check->data;

    cout<<"\nAfter removing cycle node...";
    removecycle(head);
    cout<<"\nList is circular/not : "<<floyedDetectloop(head);

    return 0;
}