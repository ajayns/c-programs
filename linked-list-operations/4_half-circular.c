#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insertAtend(struct Node *head);
void Print(struct Node* head);
struct Node *insertAtfirst(struct Node *head);
struct Node *insertAtindex(struct Node *head,int k);
struct Node *delete(struct Node *head,int n);
struct Node *deleteEnd(struct Node *head);
struct Node *reverse(struct Node* head);
struct Node *partition(struct Node* head);


int main(int argc, char const *argv[])
{
    struct Node *head=NULL;
    int x;

    printf("1 : Insert at the head in the linkedlist\n");
    printf("2 : Insert at the end in the linkedlist\n");
    printf("3 : Insert at given index in the linkedlist\n");

    printf("4 : Delete the element from the head of linkedlist\n");
    printf("5 : Delete the element from the end of linkedlist\n");
    printf("6 : Delete the element from the n'th position in the linkedlist\n");


    printf("7 : Partition linked list\n");
    printf("8 : Display the linked linkedlist\n");
    printf("9 : Exit\n");

    while(1)
    {
        int t ;
    printf("\n--------------\nEnter option:\n");
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
            printf("%s\n", "Enter the index where y want to insert :");
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
            printf("%s\n", "Enter the index which want to delete :");
            int x ;
            scanf("%d",&x);
            head = delete(head,x);          
        }
        break ;
        

        case 7 : {
            head = partition(head);
        }
        break;

        case 8 : {
            Print(head);
            }        break;

        case 9 : {
            return 0; 
        }
        break ; 
    }
}
  
    return 0;
}

struct Node* insertAtend(struct Node *head)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("%s\n", "Enter the data: ");
    scanf("%d",&(temp->data));
    
 
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    struct Node* temp1 = head;
    while(temp1->next!=NULL)
    {
        temp1=temp1->next;
    }
    temp1->next=temp;
    return head;
    
}

struct Node *insertAtfirst(struct Node *head)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //char *tempname;
    printf("%s\n", "Enter the data : ");
    scanf("%d",&(temp->data));

    


    
    //temp->name=tempname;
    temp->next=head;
    head=temp;
    return head;
}

struct Node *insertAtindex(struct Node *head,int n)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //temp->data=k;
    printf("%s\n", "Enter the roll number : ");
    scanf("%d",&(temp->data));

   

    temp->next=NULL;
    if(n==1)
    {
    	temp->next=head;
    	head=temp;
    	return head;
    	
    } 
    int i=0;
    struct Node* temp1 = head;

    for(i=0;i<n-2;i++)
    {
    	temp1=temp1->next;
    }  
    temp->next=temp1->next;
    temp1->next=temp;
    return head;
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
        printf("%s\n", "Linked listr is Empty");
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

struct Node *partition(struct Node* head){

    int n = 0;
    struct Node* temp = head;

    // Count number of elements
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    struct Node* second ;
    temp = head;
    int i=0;

    // Split at half
    for(i=1;i<n/2;i++)
    {
        temp = temp->next;
    }    
    second = temp->next;
    temp->next = NULL;


    printf("First part : ");Print(head);
    printf("Second part : ");Print(second);

    return head;
}






