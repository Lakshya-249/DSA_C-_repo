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
        cout << "memory is free for node with value : " << value << endl;
    }
};

void insert_at_tail(Node *&tail, int dat)
{
    Node *temp = new Node(dat);
    tail->next = temp;
    tail = temp;
}

Node* reverselist(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newhead=reverselist(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
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
    return step1;
}

bool find_pallindrome(Node* &head){
    Node* slow=getmiddle(head);
    Node* temp=slow->next;
    slow->next= reverselist(temp);

    Node* head1=head;
    Node* head2=slow->next;

    while(head2!=NULL){
        if(head1->data!=head2->data){
            temp=slow->next;
            slow->next=reverselist(temp);
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    temp=slow->next;
    slow->next=reverselist(temp);
    return true;
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

int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    insert_at_tail(tail, 4);
    insert_at_tail(tail, 6);
    insert_at_tail(tail, 7);
    insert_at_tail(tail, 8);
    insert_at_tail(tail, 7);
    insert_at_tail(tail, 6);
    insert_at_tail(tail, 4);
    // insert_at_tail(tail, 2);

    print(head);
    cout << endl;

    cout<<"the given list is pallindrome(0/1) : "<<find_pallindrome(head)<<endl;
    print(head);


    return 0;
}
