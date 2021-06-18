// 9. delete a specific node from a given linked list.

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


Node* delete_any(Node *start, int index)    //delete any Node of linked list index srart from 1
{
     if(index<1)
    {
      cout<<"invalid index"<<endl;
      return start;
    }
    if(index==1)
    {
        Node *ptr = start;
    
        start = start->next;
        delete (ptr);
        return start;
    }

  Node *head = start;
  int i = 1;
  while (i != index - 1 && head->next!=NULL)
  {
    head = head->next;
    i++;
  }
  Node *ptr = head->next;
  Node *temp = head->next->next;
  head->next = temp;
  delete (ptr);
  return start;
}

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
    cout<<"\nEnter the index to delete ";
    cin>>k;
    head=delete_any(head,k);
    print(head);
}