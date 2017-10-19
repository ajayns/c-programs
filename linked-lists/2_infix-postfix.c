// Convert infix to postfix
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Stack type
struct Stack{
	int top;
	int size;
	int* array;
};

// Stack Operations
struct Stack* createStack(int size){
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = size;
	stack->array = (int*) malloc(stack->size * sizeof(int));
	return stack;
}

int isEmpty(struct Stack* stack){
	return stack->top == -1 ;
}

char peek(struct Stack* stack){
	return stack->array[stack->top];
}

char pop(struct Stack* stack){
	if(!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

void push(struct Stack* stack, char op){
	stack->array[++stack->top] = op;
}


// Utility functions
int isOperand(char ch){
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int Prec(char ch){
	switch (ch)
	{
		case '+':
		case '-':
			return 1;

		case '*':
		case '/':
			return 2;

		case '^':
			return 3;
	}
	return -1;
}


int infixToPostfix(char* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	int i, k;

	for (i = 0,k = -1; exp[i]; ++i)
	{   if(isOperand(exp[i]))
		exp[++k] = exp[i];
	    else if(exp[i] == '(')
		push(stack,exp[i]);
	    // For ')' pop until '(' is encountered
	    else if (exp[i] == ')'){
		while (!isEmpty(stack) && peek(stack) != '(')
			exp[++k] = pop(stack);
		pop(stack);
		}
		// Operator case, check precedence and push/pop
	    else{
		while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
			exp[++k] = pop(stack);
		push(stack, exp[i]);
		}
	}

	// Pop remaining elements
	while (!isEmpty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "\nPostfix: %s\n", exp);
}


int main(){
	char exp[100];
	printf("\nEnter infix expression: ");
	scanf("%s",exp);
	infixToPostfix(exp);
	return 0;
}
