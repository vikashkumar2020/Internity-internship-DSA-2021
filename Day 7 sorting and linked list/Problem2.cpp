// program to delete a node from doubly linked list

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  
  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }
  
};
void deletepos(struct Node** head_ref, struct Node* del)
        {
           
            if (*head_ref == NULL || del == NULL)
                return;
        
           
            if (*head_ref == del)
                *head_ref = del->next;
        
          
            if (del->next != NULL)
                del->next->prev = del->prev;
        
            
            if (del->prev != NULL)
                del->prev->next = del->next;
        
            free(del);
        }

    Node* deleteNode(Node *head_ref, int n)
    {
       if (head_ref == NULL || n<0)
		    return NULL;
		    
	    struct Node* current = head_ref;
	    
	    for (int i = 1; current != NULL && i < n; i++)
            current = current->next;
	    
	    if (current == NULL)
        return head_ref;
        
        deletepos(&head_ref, current);
        return head_ref;
    }


void printList(struct Node *node)
{
  while(node!=NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
   printf("\n");
}
 
int main()
{
  int x, n, i;


      struct Node *temp,*head = NULL;
      scanf("%d",&n);
      
      temp = NULL;
      
      for(i=0;i<n;i++){
        scanf("%d",&x);
        
        if(head == NULL){
            head = new Node(x);
            temp = head;
        }
        else{
            Node *temp1 = new Node(x);
            temp->next = temp1;
            temp1->prev = temp;
            temp = temp->next;
        }
      }
  
    scanf("%d",&x);
      
   
    head = deleteNode(head,x); 
      
        
        printList(head);           
        while(head->next!=NULL)
        {
    	    temp=head;
    	    head=head->next;
    	    free(temp);
    	}
    	
    	free(head);

	return 0;
}