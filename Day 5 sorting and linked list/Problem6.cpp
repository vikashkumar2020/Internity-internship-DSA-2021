
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void reverse(struct Node** head_ref)
   {
        Node* prev = NULL;
        Node* current = *head_ref;
        Node* next;
     
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    *head_ref = prev;
    }
bool compareLists(Node* head1, Node* head2)
{
    Node* temp1 = head1;
    Node* temp2 = head2;
 
    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
 

    if (temp1 == NULL && temp2 == NULL)
        return 1;
 

    return 0;
}

    bool isPalindrome(Node *head)
    {
        Node *slow_ptr = head, *fast_ptr = head;
        Node *second_half, *prev_of_slow_ptr = head;
        
        Node* midnode = NULL;
        bool res = true;
        
        if (head != NULL && head->next != NULL)
        {
            while (fast_ptr != NULL && fast_ptr->next != NULL)
            {
                fast_ptr = fast_ptr->next->next;
     
                prev_of_slow_ptr = slow_ptr;
                slow_ptr = slow_ptr->next;
            }
            
            if (fast_ptr != NULL)
            {
                midnode = slow_ptr;
                slow_ptr = slow_ptr->next;
            }
            
            /* middle is found */
            
            second_half = slow_ptr;
            prev_of_slow_ptr->next = NULL;
            
            reverse(&second_half);
            
            res = compareLists(head, second_half);
            
            reverse(&second_half);
            
            if (midnode != NULL)
            {
                prev_of_slow_ptr->next = midnode;
                midnode->next = second_half;
            }
            else
                prev_of_slow_ptr->next = second_half;
                
            }
        return res;
    }

int main()
{
  int i,n,l,firstdata;
   
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

   	cout<<isPalindrome(head)<<endl;
    return 0;
}
