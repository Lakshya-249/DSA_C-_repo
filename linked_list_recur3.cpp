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

void inserttail(Node* &tail,int dat){
    Node* temp=new Node(dat);
    tail->next=temp;
    tail=temp;
}

Node* reverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp_head=reverse(head->next);
    head->next->next=head;
    head->next=NULL;

    return temp_head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1=new Node(1);
    Node* head=node1;
    Node* tail=node1;
    inserttail(tail,2);
    inserttail(tail,3);
    inserttail(tail,4);
    inserttail(tail,5);
    inserttail(tail,6);
    inserttail(tail,7);

    print(head);
    cout<<endl;
    Node* nhead = reverse(head);
    print(nhead);
    return 0;
}