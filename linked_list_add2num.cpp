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

void insert_at_tail(Node* &tail, int dat)
{
    Node *temp = new Node(dat);
    tail->next = temp;
    tail = temp;
}

int value(Node* node1){
    int val=0;
    while(node1!=NULL){
        val+=node1->data;
        if(node1->next!=NULL) val*=10;
        node1=node1->next;
    }
    return val;
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
    int val1=value(node1);
    int val2=value(node2);
    int sum=val1+val2;
    Node* node=new Node(-1);
    Node* nhead=node;
    while (sum!=0)
    {
        int div=sum%10;
        insert_at_tail(nhead,div);
        sum=sum/10;
    }
    nhead=node->next;
    delete node;
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

int main()
{
    Node *node1 = new Node(2);
    Node *head = node1;
    Node *tail = node1;

    insert_at_tail(tail, 4);
    insert_at_tail(tail, 6);
    
    print(head);
    cout << endl;

    Node *node2 = new Node(3);
    Node *head2 = node2;
    Node *tail2 = node2;

    insert_at_tail(tail2,3);
    insert_at_tail(tail2,5);

    print(head2);
    cout << endl;

    Node* sum= add2num(head,head2);
    print(sum);

    return 0;
}
