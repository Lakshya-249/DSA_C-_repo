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

void insert_at_head(Node *&head, int dat)
{
    Node *temp = new Node(dat);
    temp->next = head;
    head = temp;
}

void insert_at_tail(Node *&tail, int dat)
{
    Node *temp = new Node(dat);
    tail->next = temp;
    tail = temp;
}

void solve(Node *&head, Node *&head2)
{
    Node *cur1 = head;
    Node *next1 = cur1->next;
    Node *cur2 = head2;
    Node *next2 = cur2->next;
    if(head->next==NULL) {
        head->next=head2;
        return;
    }
    if (cur1->data > cur2->data)
    {
        // insert_at_head(head, cur2->data);
        // cur1 = head;
        // next1= cur1->next;
        // cur2 = cur2->next;
        cur2->next=cur1;
        cur1=cur2;
        cur2=next2;
        next1=cur1->next;
        head=cur1;
    }
    while (next1 != NULL && cur2 != NULL)
    {
        if (cur1->data <= cur2->data && cur2->data <= next1->data)
        {
            cur1->next = cur2;
            next2 = cur2->next;
            cur2->next = next1;
            cur1 = cur2;
            cur2 = next2;
        }
        else
        {
            cur1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                cur1->next = cur2;
                return;
            }
        }
    }
}

Node *merge_sortlist(Node *&head, Node *&head2)
{
    if (head == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head;
    }
    else
    {
        solve(head, head2);
        return head;
    }
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
    insert_at_tail(tail, 10);
    insert_at_tail(tail, 12);
    insert_at_tail(tail, 15);
    insert_at_tail(tail, 18);


    print(head);
    cout << endl;

    Node *node2 = new Node(1);
    Node *head2 = node2;
    Node *ntail = node2;
    insert_at_tail(ntail, 3);
    insert_at_tail(ntail, 5);
    insert_at_tail(ntail, 8);
    insert_at_tail(ntail, 9);
    insert_at_tail(ntail, 11);
    insert_at_tail(ntail, 14);
    insert_at_tail(ntail, 17);
    insert_at_tail(ntail, 20);

    print(head2);
    cout << endl;

    Node *newlist = merge_sortlist(head, head2);
    print(newlist);

    return 0;
}
