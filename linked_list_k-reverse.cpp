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

Node* kreverse(Node* &head,int k){
    if(head==NULL){
        return NULL;
    }
    Node* cur= head;
    Node* prev= NULL;
    Node* next= NULL;
    int ind=0;
    while(cur!=NULL && ind<k){
        next= cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        ind++;
    }
    if(next!=NULL){
        head->next=kreverse(next,k);
    }
    return prev;    
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
    inserttail(tail,8);

    print(head);
    cout<<endl;
    Node* nhead = kreverse(head,2);
    print(nhead);
    return 0;
}