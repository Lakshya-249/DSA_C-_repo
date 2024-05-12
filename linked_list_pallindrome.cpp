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

bool find_pallindrome(Node* &head){
    vector<int>vec;
    Node* temp=head;
    while (temp!=NULL)
    {
        vec.push_back(temp->data);
        temp=temp->next;
    }
    int len=vec.size()-1;
    for(int x=0;x<len/2;x++){
        if(vec[x]!=vec[len-x]) return false;
    }
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
    insert_at_tail(tail, 7);
    insert_at_tail(tail, 5);
    insert_at_tail(tail, 4);
    insert_at_tail(tail, 2);

    print(head);
    cout << endl;

    cout<<"the given list is pallindrome(0/1) : "<<find_pallindrome(head);

    return 0;
}
