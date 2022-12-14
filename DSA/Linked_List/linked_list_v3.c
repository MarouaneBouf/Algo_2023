#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node *next;
}node;

node *add_element(node *list, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = list;
    list = new_node;
    return list;
}

void display(node *list)
{
    node *temp = list;
    while(temp)
    {
        printf("%i\n",temp->data);
        temp = temp->next;
    }
}

node *add_end(node *list, int data)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    node *temp = list;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return list;
}

void main(void)
{
    node *list = NULL;
    list = add_element(list,100); // add_element == add_debut
    list = add_element(list,120);
    list = add_end(list, 1832);
    display(list);
}