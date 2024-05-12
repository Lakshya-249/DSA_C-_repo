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

void insert_node(Node* &tail,int elem,int dat){
    if(tail==NULL){
        Node* insertnod= new Node(dat);
        tail=insertnod;
        insertnod->next=insertnod;
    }else{
        Node* temp = tail;

        while(temp->data!=elem){
            temp=temp->next;
        }

        Node* insertnod = new Node(dat);
        insertnod->next=temp->next;
        temp->next=insertnod;
    }
}

void deletenode(Node* &tail,int elem){
    if(tail==NULL){
        cout<<"List is empty!!!";
        return;
    }else{
        Node* cur=tail;
        Node* prev=NULL;
        do{
            prev=cur;
            cur=cur->next;
        }while(cur->data!=elem);
        prev->next=cur->next;
        if(prev==cur){
            tail=NULL;
        }else if(tail==cur){
            tail=prev;
        }
        cur->next=NULL;
        delete cur;
    }  
}

void print(Node* tail){
    Node* temp = tail;
    if(tail==NULL){
        cout<<"List is Emplty!!!";
        return;
    }
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail!=temp);
}

int main(){
    Node* tail = NULL;
    insert_node(tail,3,5);
    insert_node(tail,5,2);
    insert_node(tail,2,3);
    insert_node(tail,2,10);
    insert_node(tail,2,11);
    insert_node(tail,2,12);
    insert_node(tail,2,13);

    print(tail);
    cout<<"\n";

    deletenode(tail,5);

    print(tail);
    cout<<"\n tail->next : "<<tail->next->data;

    return 0;
}