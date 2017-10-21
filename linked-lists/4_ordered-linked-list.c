// Linear Ordered Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure student
struct stud{
		int Roll_No;
		char Name[20];
		float CGPA;
		struct stud*next;
}*head=NULL,*temp,*save,*save2;

// Insert into the ordered linked list
void ins()
{
	char name[20];
	int roll;
    float cg;

    // Get new student data
	printf("Enter Student Roll no.:\n");
	scanf("%d",&roll);
	printf("Enter Student Name:\n");
	scanf("%s",name);
	printf("Enter Student CGPA:\n");
	scanf("%f",&cg);

	temp=(struct stud*)malloc(sizeof(struct stud));
	temp->Roll_No=roll;	
	strcpy(temp->Name,name);
	temp->CGPA=cg;
	temp->next=NULL;	

	// When list is empty
	if(head==NULL||head->Roll_No >= temp->Roll_No)
	{
		temp->next=head;
		head=temp;
	
	}
	// When list exists
	else
	{
		save=head;
		while(save->next!=NULL&&(save->next->Roll_No)<(temp->Roll_No))
    		save=save->next;
		temp->next=save->next;
    	save->next=temp;
	}
}


// Delete first element of the linked list
void del_beg()
{
	if(head==NULL)
		printf("Underflow\n");
	else
		head=head->next;
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
        while(temp->next->next!=NULL)
            temp=temp->next;
        temp->next=NULL;
    }
}

// Display
void disp()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("\n\nStudent Roll no.:%d\n",temp->Roll_No);
		printf("Student Name:%s\n",temp->Name);
		printf("Student CGPA:%f\n\n",temp->CGPA);
		temp=temp->next;
	}
}

// Search for an element in the list
void search()
{
    int s;
    int flag=0;
    printf("Enter Roll no:\n");
    scanf("%d",&s);
    temp=head;
    while(temp!=NULL)
    {
        if(s==temp->Roll_No)
        {
            flag=1;
            save=temp;
            break;            
        }
        else
            flag=0;
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("\n\nRoll no.:%s\n",save->Roll_No);
        printf("Name    :%s\n",save->Name);
        printf("CGPA    :%f\n",save->CGPA);
    }
    else
        printf("Not Available...SORRY!!!!!!!!!!!\n\n");
            
}

// Driver function
int main()
{
	int choice=0;
	while(choice!=7)
	{
		printf("1.Insert\n");
		printf("2.Delete Beginning\n");
        printf("3.Delete between\n");
        printf("4.Delete End\n");
        printf("5.Search\n");
		printf("6.Display\n");
		printf("7.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:ins();break;
			case 2:del_beg();break;
            case 3:del_pos();break;
            case 4:del_end();break;
            case 5:search();break;
            case 6:disp();break;
            default : exit(0);
        }
	}
    return 0;
}




