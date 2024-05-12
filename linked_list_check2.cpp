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
    map<Node*,bool>mpp;
    mpp[NULL]=false;
    while(mpp.find(tail)==mpp.end()){
        mpp[tail]=true;
        tail=tail->next;
    }
    if(mpp[tail]) cout<<"\nList is circular...";
    else cout<<"\nList is not circular...";
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

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* ntail = node1;

    inserttail(ntail,35);
    inserttail(ntail,45);
    inserttail(ntail,50);
    inserttail(ntail,55);
    inserttail(ntail,60);
    inserttail(ntail,65);
    inserttail(ntail,70);
    inserttail(ntail,75);

    cout<<endl;

    print(head);
    check_ll(head);
    return 0;
}