// 13 reorder list

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* newNode(int data) {
    struct Node* new_Node = new Node(data);
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}

void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {

        temp = head;
        head = head->next;
        free(temp);
    }
}

void reorderList(Node* head) {
    Node *slow = head, *fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    Node* head1 = head;
    Node* head2 = slow->next;
    slow->next = NULL;
 
  
   // reverselist(&head2);
   Node *prev = NULL, *urr = head2, *next;
 
    while (urr) {
        next = urr->next;
        urr->next = prev;
        prev = urr;
        urr = next;
    }
 
    head2 = prev;
 
    
    head = newNode(0); 
 
    Node* curr = head;
    while (head1 || head2) {
       
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
 
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
 
   
    head = (head)->next;
}


int main(void) {
    int n, m, i, x;

        struct Node* temp, *head;
        cin >> n;
        cin >> x;
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++) {
            cin >> x;
            temp->next = new Node(x);
            temp = temp->next;
        }

        reorderList(head);
        printList(head);
        freeList(head);
    return 0;
}
