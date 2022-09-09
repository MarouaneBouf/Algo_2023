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
void insert(node **head, int item, int cible);
void delete_1(node **head);
void delete_2(node **head);
void delete_3(node **head, int cible);
void display(node **head);


int main(void)
{
    /* Creating a pointer to a node. */
    node *list = NULL;
    /* Passing the address of the pointer to the first node in the linked list. */
    push(&list,172);
    append(&list,82);
    append(&list,462);
    append(&list,473);
    append(&list,32094);
    insert(&list, 999,473);
    fprintf(stdout,"\tBefore deleting the first/last element:\n");
    display(&list);

    delete_1(&list);
    delete_2(&list);
    delete_3(&list,473);
    printf("-----------------\n\tAfter Deleting the first/last element:\n");

    display(&list);


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


/* Insert a node at a certain position */
void insert(node **head, int item, int cible)
{
    node *n = malloc(sizeof(node));
    /* Assigning the value of the variable `item` to the data field of the node `n`. */
    n->data = item;
    node *tmp = *head;
    /* Traversing the linked list until it finds the node that contains the value of the variable
    `cible`. */
    while(tmp->next->data != cible)
    {
        tmp = tmp->next;
         // Defensive snippet
        /* Checking if the cible is the last node in the linked list. */
        if(temp->next == NULL)
        {
            fprintf(stdout,"Node unavailable after the cible chosen!!\n");
            exit(EXIT_FAILURE);
        }
    }
    /* Assigning the address of the new node to the pointer to the next node in the linked list. */
    n->next = tmp->next;
    tmp->next = n;
}


// Delete the first element of the linked list
void delete_1(node **head)
{
    // Store the node that's going to be deleted from the list to free it.
    node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
}


/* Delete the last node of the linked list */
void delete_2(node **head)
{
    node *temp = *head;
    for(;temp->next->next != NULL; temp = temp->next);
    temp->next = NULL;
}


// Delete a node at a certain position
void delete_3(node **head, int cible)
{
    node *tmp = *head;
    while(tmp->next->data != cible)
    {
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
}

// Displaying the elements of the linked list
void display(node **head)
{
    /* Traversing the linked list. */
    for(node *tmp = *head; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n",tmp->data);
    }
}