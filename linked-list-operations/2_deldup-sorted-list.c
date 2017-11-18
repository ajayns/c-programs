#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};

void Print(struct Node* head);
struct Node *delete(struct Node *head,int n);
struct Node *deleteEnd(struct Node *head);
struct Node* sortedInsert(struct Node* head);


struct Node *deleteDup(struct Node *head)
{
    // Pointer to traverse list
    struct Node* current = head;
    struct Node* next_next; 
   
    // If empty 
    if (current == NULL) 
       return; 
 
    // traverse till end
    while (current->next != NULL) 
    {
       // Compare with next, deletes and stays at position
       if (current->data == current->next->data) 
       {
                        
           next_next = current->next->next;
           free(current->next);
           current->next = next_next;  
       }

       else // No delete, just traverse forward
       {
          current = current->next; 
       }
    }
    return head;    
}


int main(int argc, char const *argv[])
{
    struct Node *head=NULL;
    int x;

    printf("1 : Insert the Node \n");    
    printf("2 : Delete the duplicate element \n");
    printf("3 : Display the linked list\n");
    printf("4 : Exit\n");

    while(1)
    {
        int t ;
    printf("\n\n---------------\nEnter option: \n");
    scanf("%d",&t);
    switch(t)
    {
        case 1 : {
            head = sortedInsert(head);
            
        }
        break;

        case 2 : {
           head = deleteDup(head);
            
        }break;
      
        
       case 3 : {
            Print(head);
        
        }break;
         case 4 : {
            return 0 ; 
        }
    }
}
  
    return 0;
}

struct Node *delete(struct Node *head,int n)
{
    struct Node* temp = head;
    if(n<=0)
    {
        return head;
    }
    if(n==1)
    {
        head=temp->next;
        free(temp);
        return head;
    }
    int i=0;
    for(i=0;i<n-2;i++)
    {
        temp=temp->next;
    }    
    struct Node* temppointer=temp->next->next;
    temp->next=temppointer;
    return head;
}


struct Node *deleteEnd(struct Node *head)
{
    
    if(head == NULL)
    {
        printf("%s\n", "Linked list is Empty");
        return head;
    }
    if(head->next == NULL)
    {
        head = NULL;
        return head;
    }

    struct Node* temp1 = head;
    while(temp1->next->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=NULL;
    return head;
}





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
    printf("\n\n\n");
}




struct Node* sortedInsert(struct Node* head)
{
    
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("%s\n", "Enter the data number : ");
    scanf("%d",&(temp->data));

    struct Node* current;

    if (head == NULL || head->data >= temp->data)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    else
    {
        
        current = head;
        while (current->next!=NULL &&
               current->next->data < temp->data)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;
    }

    return head;
}








