// 10. Insert a specific node from a given linked list.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;

    Node()
    {

    }
    Node(int x)
    {
        data = x;
    }
};


void print(Node *head)          // printing elements of a linked list
{
    if (head == NULL)
    {
        cout << "linked list is empty";
    }
    else
    {
        cout << "linked list ";

        while (head != NULL)
        {
            cout << head->data << "->";
            head = head->next;
        }
    }

    cout << "\n";
}

Node *insert_node_head(Node *head)            // insert from head
{
    int d;
    cout << "enter the data  ";
    cin >> d;

    if (head == NULL)
    {
        Node *newnode = new Node(d);
        head = newnode;
    }
    else
    {
        Node *newnode = new Node(d);
        newnode->next = head;
        head = newnode;
    }
    cout << d << " is inserted in linked list\n";
    return head;
}

Node* insert(Node* start,int index)// index start from 1
{
    if(index<1)
    {
      cout<<"invalid index"<<endl;
      return start;
    }
    
    int d;
    cout << "enter the data  ";
    cin >> d;
    Node* newnode =new Node(d);
    Node*head=start;
    if(index==1)
    {
       newnode->next=head;
        start=newnode;
        return start;

    }
   

     int pos=0;
     while(pos!=index-2 )
     {
         pos++;
         head=head->next;
     }
    
    Node* temp=head->next;
   
    head->next=newnode;
    newnode->next=temp;
    return start;

}

int main()
{
    Node *head = NULL;

    cout << "enter the no of elements you want to insert  ";

    int n;
    cin >> n;

    while (n--)
    {
        head = insert_node_head(head);
    }
    print(head);
    int k;
    cout<<"\nEnter the index to insert";
    cin>>k;
    head=insert(head,k);
    print(head);
}