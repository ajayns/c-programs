// Evaluate value of a postfix expression
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

// Return if stack is empty or not
int isEmpty(struct Stack* stack){
    return stack->top == -1 ;
}

// Return element on top of stack
char peek(struct Stack* stack){
    return stack->array[stack->top];
}

// Return and remove element on top of stack 
char pop(struct Stack* stack){
    if (!isEmpty(stack))
        return stack->array[stack->top--] ;
    return '$';
}

// Add element to stack
void push(struct Stack* stack, char op){
    stack->array[++stack->top] = op;
}
 
 
// The main function that returns value of a given postfix expression
int evaluatePostfix(char* exp)
{
    // Create a stack of capacity equal to expression size
    struct Stack* stack = createStack(strlen(exp));
    int i;
  
    for (i = 0; exp[i]; ++i)
    {
        // If the scanned character is an operand, push
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
 
        //  If the scanned character is an operator, pop two
        else
        {
            int val1 = pop(stack);
            int val2 = pop(stack);
            switch (exp[i])
            {
	            case '+': push(stack, val2 + val1); break;
	            case '-': push(stack, val2 - val1); break;
	            case '*': push(stack, val2 * val1); break;
	            case '/': push(stack, val2/val1);   break;
            }
        }
    }
    return pop(stack);
}
 
// Driver function
int main()
{
	char exp[100];
	printf("\nEnter postfix expression: ");
	scanf("%s",exp);
    printf("Value of %s is %d", exp, evaluatePostfix(exp));
    return 0;
}