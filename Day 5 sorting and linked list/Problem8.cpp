// reverse a linked list
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

    struct Node* reverseList(struct Node *head)
    {
        if(head->next==NULL)
        return head;
        
        Node* current=head;
        Node* prev=NULL;
        Node* next;
        
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    head = prev;
    }

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

int main()
{
    int n,l,firstdata;

        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        
        head = reverseList(head);
        
        printList(head);
        cout << endl;
  
    return 0;
}
