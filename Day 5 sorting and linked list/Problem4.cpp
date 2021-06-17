// 4.  Intersection Point in Y Shapped Linked Lists 

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
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



int intersectPoint(Node* head1, Node* head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
   
    int l1=0;
    int l2 =0;
    
    while(temp1!=NULL)
    {
        temp1 = temp1->next;
        l1++;
    }
    while(temp2!=NULL)
    {
        temp2 = temp2->next;
        l2++;
    }
    
    int diff = abs(l2-l1);
    temp1 = head1;
    temp2 = head2;
    if(l1>l2)
    {
        while(diff--)
        {
            temp1=temp1->next;
        }
    }
    else
    {
        while(diff--)
        {
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        if(temp1==temp2)
        return temp1->data;
         temp1=temp1->next;
         temp2=temp2->next;
    }
    
    return -1;
    
}



Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}


int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}
