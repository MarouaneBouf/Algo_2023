#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Node is a type that is a pointer to a structure that contains an int and a pointer to a node.
 * @property {int} data - This is the data that you want to store in the node.
 * @property next - This is a pointer to the next node in the list.
 */
typedef struct node
{
    int data; // Whatever data you want it could be literally a structure
    struct node *next;
}node;



int main(void)
{
    /* Creating a pointer to a node and setting it to NULL. */
    node *list = NULL;


    // Adding the first element into the linked list
    node *node_1 = malloc(sizeof(node));
    if(node_1 == NULL)
    {
        return 1;
    }
    node_1->data =  100;
    node_1->next = NULL;

    list = node_1;

    // Add another element into the list
    node_1 = malloc(sizeof(node));
/* This is checking to see if the memory allocation was successful. If it was not successful then it
will free the memory that was allocated and return 1. */
    if(node_1 == NULL)
    {
        free(list);
        return 1;
    }
/* Setting the data to 817 and the next pointer to NULL. */
    node_1->data = 817;
    node_1->next = NULL;

/* Setting the next pointer of the list to the node_1. */
    list->next = node_1;

    // Adding a final element
    node_1 = malloc(sizeof(node));
    if(node_1 == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
/* Adding a new node to the end of the list. */
    node_1->data = 7232;
    node_1->next = NULL;

    list->next->next = node_1;

/* This is a for loop that is iterating through the linked list and printing out the data. */
    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        fprintf(stdout,"%i\n",tmp->data);
    }


/* This is freeing the memory that was allocated for the linked list. */
    while(list != NULL)
    {
        /* Setting the tmp pointer to the next node in the list. */
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;
}