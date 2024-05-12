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

void insertnode(Node* &tail,int elem,int data){
    if(tail==NULL){
        Node* temp =new Node(data);
        tail=temp;
        temp->next=temp;
    }else{
        Node* insertnd=new Node(data);
        Node* temp =tail;
        Node* temp2=tail;
        while(temp->data!=elem && temp!=temp2){
            temp=temp->next;
        }
        insertnd->next=temp->next;
        temp->next=insertnd;
    }
}

void check_ll(Node* tail){
    Node* temp=tail;
    while(tail!=temp && tail!=NULL){
        tail = tail->next;
    }
    if(tail==temp){
        cout<<"\nLinked list is Circular..."<<endl;
    }else{
        cout<<"\nLinked List is not Cirluar..."<<endl;
    }
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
    }while(tail!=temp);
}

int main(){
    Node* tail=NULL;

    insertnode(tail,1,10);
    insertnode(tail,10,11);
    insertnode(tail,10,12);
    insertnode(tail,10,13);
    insertnode(tail,10,14);
    insertnode(tail,10,15);
    insertnode(tail,10,16);
    insertnode(tail,10,17);
    insertnode(tail,10,18);

    print(tail);
    check_ll(tail);
    return 0;
}