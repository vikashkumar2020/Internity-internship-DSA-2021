#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};


Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* result = NULL;
     
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;
     
    if (head1->data <= head2->data)
    {
        result = head1;
        result->next = sortedMerge(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = sortedMerge(head1, head2->next);
    }
    return result;
}  


void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{

        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    return 0;
}

