#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            this->next = NULL;
            delete next;
        }
        // cout << "memory is free for node with value : " << value << endl;
    }
};

void insert_at_tail(Node* &head,Node* &tail, int dat){
    Node *temp = new Node(dat);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }else{
        tail->next=temp;
        tail=temp;
    }
}

Node* reverse(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return temp;
}

Node* add2num(Node* node1,Node* node2){
    Node* temp1=reverse(node1);
    Node* temp2=reverse(node2);
    Node* nhead=NULL;
    Node* ntail=NULL;
    int carry=0,sum=0;
    while(temp1!=NULL || temp2!=NULL || carry!=0){
        int val1=0,val2=0;
        if(temp1!=NULL){
            val1=temp1->data;
            temp1=temp1->next;
        } 
        if(temp2!=NULL){
            val2=temp2->data;
            temp2=temp2->next;
        }

        sum=val1+val2+carry;
        carry=sum/10;
        sum=sum%10;
        insert_at_tail(nhead,ntail,sum);
    } 
    
    nhead=reverse(nhead);
    return nhead;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){

    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    insert_at_tail(head,tail, 4);
    insert_at_tail(head,tail, 6);
    insert_at_tail(head,tail,7);
    
    print(head);
    cout << endl;

    Node *node2 = new Node(9);
    Node *head2 = node2;
    Node *tail2 = node2;

    insert_at_tail(head2,tail2,3);
    // insert_at_tail(tail2,5);

    print(head2);
    cout << endl;

    Node* sum= add2num(head,head2);
    print(sum);

    return 0;
}
