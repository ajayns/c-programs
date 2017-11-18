#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure definition
struct Node
{
    int data;
    struct Node *next;
    struct Node * prev;
};

// Function prototypes
struct Node *insertAtend(struct Node *head);
void Print(struct Node* head);
struct Node *insertAtfirst(struct Node *head);
struct Node *insertAtindex(struct Node *head,int k);
struct Node *delete(struct Node *head,int n);
struct Node *deleteEnd(struct Node *head);
void reverse(struct Node **head_ref);

// Driver function
int main(int argc, char const *argv[])
{
    struct Node *head=NULL;
    int x;

    // Menu in loop
    printf("1. Insert at the head in the linkedlist\n");
    printf("2. Insert at the end in the linkedlist\n");
    printf("3. Insert at given index in the linkedlist\n");

    printf("4. Delete the element from the head of linkedlist\n");
    printf("5. Delete the element from the end of linkedlist\n");
    printf("6. Delete the element from the n'th position in the linkedlist\n");


    printf("7. Reverse the doubly linked list \n");
    printf("8. Display the linked linkedlist\n");
    printf("9. Exit\n");

    while(1)
    {
        int t ;
    printf("\n\n-------------------\nEnter option: \n");
    scanf("%d",&t);
    switch(t)
    {
        case 1 : {
            head = insertAtfirst(head);
            
        }
        break;

        case 2 : {
            head = insertAtend(head);
            
        }break;
        case 3 : {
            printf("%s\n", "Enter the index where you want to insert:");
            int x ;
            scanf("%d",&x);
            head = insertAtindex(head,x);
            
        }break;
        case 4 :{
                head = delete(head,1);
        }break;
        case 5 :{
                head = deleteEnd(head);
        }break;
        
        case 6 : {
            printf("%s\n", "Enter the index which want to delete:");
            int x ;
            scanf("%d",&x);
            head = delete(head,x);          
        }
        break ;
        case 7: {
            reverse(&head);
        }
        break;
        case 8 : {
            Print(head);
        }
        break;

        case 9 : {
            return ; 
        }
        break ; 
    }
}
  
    return 0;
}


// Insert at end of list
struct Node* insertAtend(struct Node *head)
{
    // Allocate space for new node and get data
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("%s\n", "Enter the data number : ");
    scanf("%d",&(temp->data));
    
    temp->next=NULL;
    temp->prev=NULL;

    // If no queue
    if(head==NULL)
    {
        head=temp;
        return head;
    }

    // Traverse through list
    struct Node* temp1 = head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    
    // Assign values
    temp->prev=temp1;
    temp1->next=temp;
    return head;
}


// Insert at beginning of the list 
struct Node *insertAtfirst(struct Node *head)
{
    // Allocate space for new node and get data
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("%s\n", "Enter the data number : ");
    scanf("%d",&(temp->data));

    temp->prev = NULL;
    temp->next = NULL;

    // If no queue
    if(head == NULL)
    {
        return temp;
    }
    
    // Assign data
    temp->next=head;
    head->prev = temp;
    head=temp;
    return head;
}


// Insert node at given position
struct Node *insertAtindex(struct Node *head,int n)
{
    // Allocate space for new node and get data
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));    
    printf("%s\n", "Enter the data number : ");
    scanf("%d",&(temp->data));

    temp->prev=NULL;
    temp->next=NULL;

    // If insert at beginning
    if(n==1)
    {
    	temp->next=head;
        head->prev=temp;
    	head=temp;
    	return head;
    	
    } 

    int i=0;
    struct Node* temp1=head;

    // Insert at positon
    for(i=0;i<n-2;i++)
    {
    	temp1=temp1->next;
    }  

    temp->next=temp1->next;
    temp->prev=temp1;
    temp1->next=temp;
    return head;
}

// Delete node at given position 
struct Node *delete(struct Node *head,int n)
{
    struct Node* temp=head;
    
    // If entered invalid position
    if(n<=0)
    {
        return head;
    }

    // If first position
    if(n==1)
    {
        head=temp->next;
        head->prev=NULL;
        free(temp);
        return head;
    }

    int i=0;
    for(i=0;i<n-2;i++)
    {
        temp=temp->next;
    }    
    struct Node* temppointer=temp->next->next;
    if(temp->next->next != NULL)
    {
        temp->next->next->prev = temp;
    }
    temp->next=temppointer;
    return head;
}

// Delete last node
struct Node *deleteEnd(struct Node *head)
{
    // If empty list
    if(head == NULL)
    {
        printf("%s\n", "Linked list is Empty");
        return head;
    }

    // If only one node
    if(head->next == NULL)
    {
        head = NULL;
        return head;
    }

    // Traverse to end and delete
    struct Node* temp1 = head;
    while(temp1->next->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=NULL;
    return head;
}

// Display whole list
void Print(struct Node* head)
{
    if(head == NULL)
    {
        printf("%s\n", "Linked list is Empty");
        return;
    }
    struct Node* temp1 = head;
    while(temp1!=NULL)
    {
        
        printf("%d ", temp1->data);   
        temp1=temp1->next;
    }
    printf("\n\n");
}


// Reverse elements in list
void reverse(struct Node **head_ref)
{
     struct Node *temp = NULL;  
     struct Node *current = *head_ref;
      
     // For doubly linked list, just swap each nodes' next and prev pointer to reverse
     while (current !=  NULL)
     {
       temp = current->prev;
       current->prev = current->next;
       current->next = temp;              
       current = current->prev;
     }      
      
     
     if(temp != NULL )
        *head_ref = temp->prev;
}     


