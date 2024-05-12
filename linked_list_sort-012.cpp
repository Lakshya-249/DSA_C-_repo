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

void insert_at_tail(Node* &tail,int dat){
    Node* temp = new Node(dat);
    tail->next=temp;
    tail=temp;
}

void sortlist(Node* &head){
    Node* temp= head;
    int zero=0,one=0,two=0;
    while(temp!=NULL){
        if(temp->data==0){
            zero++;
        }else if(temp->data==1){
            one++;
        }else if(temp->data==2) two++;
        temp=temp->next;
    }
    temp=head;
    while (temp!=NULL)
    {
        if(zero!=0){
            temp->data=0;
            zero--;
        }else if(one!=0){
            temp->data=1;
            one--;
        }else if(two!=0){
            temp->data=2;
            two--;
        }
        temp=temp->next;
    }
    
}

void print(Node* &head){
    Node* temp = head;
    while (temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;

    insert_at_tail(tail,0);
    insert_at_tail(tail,1);
    insert_at_tail(tail,2);
    insert_at_tail(tail,0);
    insert_at_tail(tail,2);
    insert_at_tail(tail,1);
    insert_at_tail(tail,2);
    insert_at_tail(tail,0);
    insert_at_tail(tail,1);
    insert_at_tail(tail,0);
    insert_at_tail(tail,2);
    
    print(head);
    cout<<endl;

    sortlist(head);
    print(head);

    return 0;
}
