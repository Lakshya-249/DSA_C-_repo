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

Node* getmiddle(Node* &head){
    Node* step1=head;
    Node* step2=head->next;
    if(head==NULL || head->next==NULL){
        return head;
    }
    while(step2!=NULL && step2->next!=NULL){
        step1=step1->next;
        step2=step2->next->next;
    }
    // while(step2!=NULL){
    //     step2=step2->next;
    //     if(step2!=NULL){
    //         step2=step2->next;
    //     }
    //     step1=step1->next;
    // }

    return step1;
}

void print(Node* head){
    Node* temp=head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
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
    inserttail(tail,8);
    inserttail(tail,9);

    print(head);
    cout<<endl;

    Node* mid = getmiddle(head);
    cout<<"Middle element of the list : "<<mid->data;
    return 0;
}