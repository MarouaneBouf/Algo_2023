#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/*
 * A node is a structure that contains an integer and a pointer to a node.
 * @property {int} data - This is the data that the node will hold.
 * @property next - This is a pointer to the next node in the list.
 */
typedef struct node
{
    int data;
    struct node *next;
}node;

/* Passing the address of the pointer to the first node in the linked list. */
void push(node **head, int item);
void append(node **head, int item);

int main(void)
{
    /* Creating a pointer to a node. */
    node *list = NULL;
    /* Passing the address of the pointer to the first node in the linked list. */
    push(&list,172);
    append(&list,82);

    /* Traversing the linked list. */
    for(node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n",tmp->data);
    }
    return 0;
}

// Inserting an element at the start of the linked list
void push(node **head, int item)
{
    node *new_node = malloc(sizeof(node));
/* Checking if the memory allocation was successful. */
    if(new_node == NULL)
    {
        fprintf(stdout,"Runs out of memory!!\n");
    }
    else
    {
        new_node->data = item;
        new_node->next = *head;
        /* Assigning the address of the new node to the pointer to the first node in the linked list. */
        *head = new_node;
    }
}

// Inserting an element the end of the list

void append(node **head, int item)
{
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("No memo available!\n");
    }
    else
    {
        n->data = item;
        n->next = NULL;
        /* Assigning the address of the first node in the linked list to the pointer `tmp`. */
        node *tmp = *head;
        /* Traversing the linked list until it reaches the last node. */
        for(; tmp->next != NULL; tmp = tmp->next);
        /* Assigning the address of the new node to the pointer to the next node in the linked list. */
        tmp->next = n; 
    }
}