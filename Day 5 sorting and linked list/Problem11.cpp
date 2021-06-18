// 11. delete a node whose pointer to that node is given only.

#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}


void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}



    void deleteNode(Node *del)
    {
        Node* temp = del->next->next;
        del->data=del->next->data;
       
       Node* ptr = del->next;
       delete(ptr);
       del->next=temp;
       
    }



int main(void)
{


    int k,n,value;
    

        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);

        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    
    return(0);
}
