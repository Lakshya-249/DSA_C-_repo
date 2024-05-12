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

int getlength(Node* head){
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

Node* getmiddle(Node* head){
    int mid = getlength(head)/2;
    int ind=0;
    while(ind!=mid){
        head=head->next;
        ind++;
    }
    return head;
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

    print(head);
    cout<<endl;

    int len = getlength(head);
    cout<<"Lenth of list: "<<len<<endl;

    Node* mid = getmiddle(head);
    cout<<"Middle element of the list : "<<mid->data;
    return 0;
}