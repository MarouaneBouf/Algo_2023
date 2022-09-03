/* Importing the standard libraries for C. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/* Defining a constant called MAX with the value 10. */
#define MAX 10
/* A global variable that is used to keep track of the number of elements in the stack. */
int count = 0;

/*
 * A stack is a structure that contains an array of integers, and an integer that represents the top of
 * the stack.
 * @property {int} items - This is the array that holds the stack items.
 * @property {int} top - This is the index of the topmost element of the stack.
 */
typedef struct stack
{
    int items[MAX];
    int top;
}stack;


/* This is a function prototype. It is telling the compiler that there are two functions called
`create_stack` and `push` that take in a `stack` pointer and an `int` respectively. */
void create_stack(stack *st);
void push(stack *st, int new_item);
int is_empty(stack *st);
int is_full(stack *st);
void pop(stack *st);
void print_stack(stack *st);


/* The entry point of the program. */
int main(void)
{
    /* Allocating memory for the stack. */
    stack *stack_1 = (stack *)malloc(sizeof(stack));
/* Calling the function `create_stack` and passing in the stack `stack_1` as an argument. */
    create_stack(stack_1);
/* Pushing the values 10, 150 and 54 onto the stack. */
    push(stack_1, 10);
    push(stack_1, 150);
    push(stack_1, 54);

    /* Printing out the elements of the stack. */
    print_stack(stack_1); 

/* Freeing the memory that was allocated to the stack. */
    free(stack_1);
    return 0;
}


/* Checking if the stack is empty. */
int is_empty(stack *st)
{
    return (st->top == -1)?1:0;
}

void create_stack(stack *st)
/*
 * It creates a stack
 * 
 * @param stack_1 This is the name of the stack that we want to create.
 */
{
    st->top = -1;
}


void push(stack *st, int new_item)
/*
 * Push a new item onto the stack.
 * 
 * @param st This is the stack that we want to push an item onto.
 * @param new_item The item to be pushed onto the stack.
 */
{
    /* Checking if the stack is full. If it is, then it prints out a message saying that the stack is
    full. */
    if(is_full(st)) fprintf(stdout,"Stack is full!\n");
/* Incrementing the value of `st->top` by 1, and then assigning 
the value of `new_item` to the element at index `st->top` of the array `st->items`.*/
    st->items[++st->top] = new_item;
    count ++;
}

/* Checking if the stack is full. */
int is_full(stack *st)
{
    /* Checking if the value of `st->top` is equal to `MAX-1`. If it is, then it returns 1, otherwise
    it returns 0. */
    return (st->top == MAX-1)?1:0;
}


void pop(stack *st)
/*
 * It pops the top element of the stack.
 * 
 * @param st pointer to the stack
 */
{
    if(is_empty(st))
    {
/* Printing out the message "Stack is empty!" to the standard output. */
        fprintf(stdout,"Stack is empty!\n");
    }
    /* Printing out the value of the topmost element of the stack. */
    printf("Item popped= %i\n",st->items[st->top]);
    /* Decrementing the value of `st->top` by 1. */
    st->top--;
    count --;
}


void print_stack(stack *st)
/*
 * It prints the elements of the stack
 * 
 * @param st The stack to print
 */
{
    fprintf(stdout,"Stack elements are: ");
    for(int i = 0; i < count ; i++)
    {
        /* Printing out the value of the element at index `i` of the array `st->items`. */
        printf("%i ",st->items[i]);
    }
    printf("\n");
}

