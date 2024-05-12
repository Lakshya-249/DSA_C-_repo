#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int val){
            this->data=val;
            this->next=NULL;
        }
};

class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

void insertatail(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
    return;
}

Node* merge_nlinkedlist(vector<Node*>arr){
    int size=arr.size();
    priority_queue<Node*,vector<Node*>,compare>minh;
    for(int i=0;i<size;i++){
        minh.push(arr[i]);
    }
    Node* head=NULL;
    Node* tail=NULL;
    while (!minh.empty())
    {
        Node* val=minh.top();
        minh.pop();
        if(val->next!=NULL){
            minh.push(val->next);
        }
        if(head==NULL){
            head=val;
            tail=val;
        }
        else{
            tail->next=val;
            tail=val;
        }
    }
    return head;
}

void printlist(Node* head){
    if(head==NULL){
        cout<<"The list is empty...";
        return;
    }
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
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
    cout<<"Printing the first linked list: ";
    printlist(head);

    Node* head2=NULL;
    Node* tail2=NULL;
    insertatail(head2,tail2,12);
    insertatail(head2,tail2,13);
    insertatail(head2,tail2,14);
    insertatail(head2,tail2,25);
    insertatail(head2,tail2,26);
    insertatail(head2,tail2,27);
    insertatail(head2,tail2,28);
    insertatail(head2,tail2,29);
    insertatail(head2,tail2,30);
    cout<<"\nPrinting the second linked list: ";
    printlist(head2);

    Node* head3=NULL;
    Node* tail3=NULL;
    insertatail(head3,tail3,15);
    insertatail(head3,tail3,16);
    insertatail(head3,tail3,17);
    insertatail(head3,tail3,18);
    insertatail(head3,tail3,19);
    insertatail(head3,tail3,20);
    insertatail(head3,tail3,31);
    insertatail(head3,tail3,32);
    insertatail(head3,tail3,33);
    cout<<"\nPrinting the third linked list: ";
    printlist(head3);

    vector<Node*>arr{head,head2,head3};
    Node* newnode=merge_nlinkedlist(arr);
    cout<<"\nPrinting te new linked list-->\n";
    printlist(newnode);

}