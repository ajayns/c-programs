// Linear Circular Linked List


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure student
struct stud{
		char Roll_No[9];
		char Name[20];
		float CGPA;
		struct stud*next;
}*save1,*head=NULL,*temp,*save,*save2;

// Insert at the end of the linked list
void ins_last()
{
	char roll[9],name[20];
	float cg;
	
	// Get new student data
	printf("Enter Student Roll no.:\n");
	scanf("%s",roll);
	printf("Enter Student Name:\n");
	scanf("%s",name);
	printf("Enter Student CGPA:\n");
	scanf("%f",&cg);

	temp=(struct stud*)malloc(sizeof(struct stud));
	strcpy(temp->Roll_No,roll);	
	strcpy(temp->Name,name);
	temp->CGPA=cg;
	temp->next=head;	

	// When list is empty
	if(head==NULL)
		head=temp;
	
	// When list exists
	else
    {	temp->next=head;
		save=head;
		do
		{
			save=save->next;
		} while(save->next!=head);
		save->next=temp;
	}
}

// Insert into the beginning of the linked list
void ins_beg()
{
	char roll[9],name[20];
	float cg;

	// Get new student data
	printf("Enter Student Roll no.:\n");
	scanf("%s",roll);
	printf("Enter Student Name:\n");
	scanf("%s",name);
	printf("Enter Student CGPA:\n");
	scanf("%f",&cg);

	temp=(struct stud*)malloc(sizeof(struct stud));
	strcpy(temp->Roll_No,roll);	
	strcpy(temp->Name,name);
	temp->CGPA=cg;
	temp->next=NULL;	

	// If list is empty
	if(head==NULL)
	{
		head=temp;
		head->next=head;
	}	

	// If list exists
	else
	{
		save=head;
		head=temp;
		temp->next=save;
		save1=save;
		do
		{
			save1=save1->next;
		} while(save1->next!=save);
		save1->next=temp;
	}
}

// Insert in a specified position
void ins_pos()
{
	int pos;
    char roll[9],name[20];
	float cg;

	// Get new student data
	printf("Enter Student Roll no.:\n");
	scanf("%s",roll);
	printf("Enter Student Name:\n");
	scanf("%s",name);
	printf("Enter Student CGPA:\n");
	scanf("%f",&cg);
    printf("Enter Position:\n");
	scanf("%d",&pos);

    temp=(struct stud*)malloc(sizeof(struct stud));
	strcpy(temp->Roll_No,roll);	
	strcpy(temp->Name,name);
	temp->CGPA=cg;
	temp->next=NULL;

	// If list is empty
	if(head==NULL)
		head=temp;

	// If list exists
	else
	{   save=head;
        pos-=1;
		while(--pos)
            save=save->next;
        save2=save->next;
        save->next=temp;
        temp->next=save2;
	}
}

// Delete first element of the linked list
void del_beg()
{
	if(head->next==head)
		head=NULL;
	if(head==NULL)
		printf("Underflow\n");
	else
	{
		save=head;
		do
		{
			save=save->next;
		} while(save->next!=head);
		save->next=save->next->next;
		head=head->next;
		
	}
}

// Delete element in the given position
void del_pos()
{
	int pos;
    printf("Enter Position:\n");
	scanf("%d",&pos);
    if(head==NULL)
		printf("Underflow\n");
	else
    {
        save=head;
        pos--;
        while(--pos)
            save=save->next;
        save->next=save->next->next;
        
    }
}

// Delete last element in linked list
void del_end()
{
	if(head==NULL)
		printf("Underflow\n");
	else
    {
        temp=head;
        while(temp->next->next!=head)
            temp=temp->next;
        temp->next=head;
    }
}

// Display
void disp()
{
	temp=head;
	do
	{
		printf("\n\nStudent Roll no.:%s\n",temp->Roll_No);
		printf("Student Name:%s\n",temp->Name);
		printf("Student CGPA:%f\n",temp->CGPA);
		temp=temp->next;
	} while(temp!=head);
}

// Search for an element in the list
void search()
{
    char s[100];
    int flag=0;
    printf("Enter Roll no:\n");
    scanf("%s",s);
    temp=head;
    do
    {
        if(!strcmp(s,temp->Roll_No))
        {
            flag=1;
            save=temp;
            break;            
        }
        else
            flag=0;
        temp=temp->next;
    } while(temp!=head);
    if(flag==1)
    {
        printf("\n\nStudent Roll no.:%s\n",save->Roll_No);
        printf("Student Name:%s\n",save->Name);
        printf("Student CGPA:%f\n",save->CGPA);
    }
    else
        printf("Not Found\n");
            
}

// Driver function
int main()
{
	int choice=0;
	while(choice!=9)
	{
		printf("1.Insert Beginning\n");
        printf("2.Insert Between\n");
        printf("3.Insert End\n");
		printf("4.Delete Beginning\n");
        printf("5.Delete between\n");
        printf("6.Delete End\n");
        printf("7.Search\n");
		printf("8.Display\n");
		//printf("4.Peek\n");
		printf("9.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:ins_beg();break;
			case 2:ins_pos();break;
			case 3:ins_last();break;
			case 4:del_beg();break;
            case 5:del_pos();break;
            case 6:del_end();break;
            case 7:search();break;
            case 8:disp();break;
            //case 9:exit(0);break;    
        }
	}
    return 0;
}

