// Linear Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure student
struct stud{
	char Roll_No[9];
	char Name[20];
	float CGPA;
	struct stud*next;
}*head=NULL,*temp,*save,*save2;

// Insert at the end of the linked list
void ins_last()
{
	char roll[9],name[20];
	float cg;

	// Get new student data
	printf("Enter the Roll no.:\n");
	scanf("%s",roll);
	printf("Enter Name:\n");
	scanf("%s",name);
	printf("Enter CGPA:\n");
	scanf("%f",&cg);

	temp=(struct stud*)malloc(sizeof(struct stud));
	strcpy(temp->Roll_No,roll);	
	strcpy(temp->Name,name);
	temp->CGPA=cg;
	temp->next=NULL;	
	if(head==NULL)
		head=temp;
	
	else
	{   save=head;
		while(save->next!=NULL)
			save=save->next;
		save->next=temp;
		save=temp;
	}
}

// Insert into the beginning of the linked list
void ins_beg()
{
	char roll[9],name[20];
	float cg;

	// Get new student data
	printf("Enter the Roll no.:\n");
	scanf("%s",roll);
	printf("Enter Name:\n");
	scanf("%s",name);
	printf("Enter CGPA:\n");
	scanf("%f",&cg);

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
	{
		save=head;
		head=temp;
		temp->next=save;
	}
}

// Insert in a specified position
void ins_pos()
{
	int pos;
	char roll[9],name[20];
	float cg;

	// Get new student data
	printf("Enter the Roll no.:\n");
	scanf("%s",roll);
	printf("Enter Name:\n");
	scanf("%s",name);
	printf("Enter CGPA:\n");
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
		printf("\n\nRoll no.:%s\n",temp->Roll_No);
		printf("Name    :%s\n",temp->Name);
		printf("CGPA    :%f\n\n",temp->CGPA);
		temp=temp->next;
	}
}

// Search for an element in the list
void search()
{
	char s[100];
	int flag=0;
	printf("Enter Roll no:\n");
	scanf("%s",s);
	temp=head;
	while(temp!=NULL)
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
	}
	if(flag==1)
	{
		printf("Roll no.:%s\n",save->Roll_No);
		printf("Name    :%s\n",save->Name);
		printf("CGPA    :%f\n",save->CGPA);
	}
	else
		printf("No results found.\n\n\n");
}

// Driver function
int main()
{
	int ch=0;
	while(ch!=9)
	{
		printf("1.Insert at Beginning\n");
		printf("2.Insert at Position\n");
		printf("3.Insert at End\n");
		printf("4.Delete from Beginning\n");
		printf("5.Delete at Position\n");
		printf("6.Delete from End\n");
		printf("7.Search\n");
		printf("8.Display\n");
		printf("9.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:ins_beg();break;
			case 2:ins_pos();break;
			case 3:ins_last();break;
			case 4:del_beg();break;
			case 5:del_pos();break;
			case 6:del_end();break;
			case 7:search();break;
			case 8:disp();break;    
			default : exit(0);
		}
	}
	return 0;
}
