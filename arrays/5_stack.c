// Basic stack operations in an array

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

// Stack structure
struct Book{
	int id;
	float price;
	char name[20];
};


// Function prototypes
void push();
void pop();
void peep();
void display();

int top = -1;
struct Book bookstack[MAXSIZE];

// Check overflow and underflow conditions
int isFull(){
	if(top == MAXSIZE)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}

void main(){
	int choice;
	struct Book book;

	do{
		printf("-------------------\n");
		printf("1 Push\n2 Pop\n3 Peek\n4 Display\n5 Exit\n");
		printf("-------------------\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:push();break;
			case 2:pop();break;
			case 3:peep();break;
			case 4:display();break;
			case 5:exit(0);
			default:printf("please enter a valid choice \n"); break;
		}
	}while(1);
}

// Pop the top element from stack
void pop() {
	struct Book book;
	if(!isEmpty()) {
		book = bookstack[top--]; 
		printf("Item popped with values, \n");
		printf("Id: %d \n",book.id);
		printf("Name: %s\n", book.name);
		printf("Price: %f \n",book.price);
	}else{
		printf("Could not retrieve data, Stack is empty.\n");
	}
}

// Add a new element to top of stack
void push(){	
	if(!isFull()) {
		top++;   
		printf("Enter book's details (Id, Name, Price): \n");
		scanf("%d %s %f",&bookstack[top].id,bookstack[top].name,&bookstack[top].price);
	}else {
		printf("Could not insert data, Stack is full.\n");
	}
}

// Display all elements of stack
void display(){
	if(isEmpty()){
		printf("No items to display.\n");
	} else {
		struct Book book;
		int dtop=top;
		book=bookstack[top];
		
		printf("\n\nId:\tName:\tPrice:\n");
		while(dtop>=0){
			book=bookstack[dtop--];			
			printf("%d\t",book.id);
			printf("%s\t",book.name);
			printf("%f\t\n",book.price);
		}
		printf("\n\n");
	}
}

// Display top element of stack
void peep(){
	struct Book book;
	int op;
	printf("Enter element to peep: ");
	scanf("%d",&op);
	book=bookstack[op];
	printf("Selected element has values \n");
	printf("Id: %d \n",book.id);
	printf("Name: %s \n",book.name);
	printf("Price: %f \n",book.price);
}
