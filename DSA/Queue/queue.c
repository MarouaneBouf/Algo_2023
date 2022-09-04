#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


/* It's defining the maximum number of elements that can be inserted in the queue. */
#define MAX 10
/* FRONT :It's a pointer that keeps track of the first element in the queue. */
/* REAR :It's setting the pointer to the last element of the queue to -1 which means that
the queue is empty. */
int FRONT = -1 , REAR = -1;

/*
 * A queue is a structure that contains an array of integers.
 * @property {int} items - This is the array that holds the items in the queue.
 */
typedef struct queue
{
    int items[MAX];
}queue;

/* It's declaring the functions that we are going to use. */
void display(queue *Queue_1);
void enqueue(queue *Queue_1, int new_item);
void dequeue(queue *Queue_1);


int main(void)
{
/* It's allocating memory for the queue. */
    queue  *Queue_1 = (queue *)malloc(sizeof(queue));

/* It's adding 3 elements to the queue. */
    enqueue(Queue_1, 19);
    enqueue(Queue_1, 72);
    enqueue(Queue_1, 37);

/* It's removing the first element of the queue. */
    dequeue(Queue_1);

 /* It's printing the elements of the queue. */
    display(Queue_1);


/* It's freeing the memory that was allocated for the queue. */
    free(Queue_1);
    return 0;
}


/*
 * It checks if the queue is full.
 * 
 * @param Queue_1 The queue that we want to check if it's full or not.
 * 
 * @return a boolean value.
 */


void enqueue(queue *Queue_1, int new_item)
{
    if (REAR == MAX - 1)
    {
        fprintf(stdout,"The Queue is full!\n");
    }
    else
    {
        if (FRONT == -1)
        {
            FRONT = 0;
        }
        printf("Element Added: %i\n",new_item);
        Queue_1->items[++REAR] = new_item;
    }
}



/*
 * If the queue is not empty, then print the element at the front of the queue and increment the front
 * index
 * 
 * @param Queue_1 The queue that you want to dequeue from.
 */
void dequeue(queue *Queue_1)
{
    if(REAR == -1)
    {
        fprintf(stdout,"The queue is empty!\n");
    }
    else
    {
        printf("element popped: %i\n",Queue_1->items[FRONT++]);
        if (FRONT > REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
    }
}

void display(queue *Queue_1)
{
/* It's checking if the queue is empty. */
    if(REAR == -1)
    {
        fprintf(stdout,"Queue is empty!\n");
    }
    else
    {
/* It's printing the elements of the queue. */
        for(int i = FRONT; i <= REAR ; i++)
        {
/* It's printing the elements of the queue. */
            fprintf(stdout,"Element %02i: %i\n",i+1,Queue_1->items[i]);
        }
    }
}

/*

Queue follows FIFO concept which is first in first out.
We need two pointers, one that keeps track of the first element in the queue and
the other one keeps track of the last element.

When implementing the queue with an array, the amount of element that can be
inserted is limited (so it's prefered to use a Linked list instead!)

There are few functions that we can perform using Queues:
-> enqueue (Add elements to the last of the queue)
-> dequeue (Remove the first element of the queue based on FIFO)
-> is_full : in case we are using an array implementation
-> is_empty : check if Rear = -1 which means the queue is empty (no elements)
-> peek : pop the first element of the queue

*/