#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

void print_tree(node *root);
void free_tree(node *root);
bool search(node *root, int number);

int main(void)
{
    node *tree = NULL;

    // Add a node to the tree
    node *root = malloc(sizeof(node));
    if (root == NULL)
    {
        return 1;
    }
    
    root->data = 2;
    root->left = NULL;
    root->right = NULL;
    tree = root;

    // add another node to the left of the root
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        
        return 1;
    }    
    root->left = NULL;
    root->right = NULL;
    root->data = 1;
    tree->left = root;

    // Add another element
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        
        return 1;
    }
    root->left = NULL;
    root->right = NULL;
    root->data = 3;
    tree->right = root;
    
    print_tree(tree);
    printf("%s\n",(search(tree,6))?"TRUE":"FALSE");
    free_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    if(root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}


void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n",root->data);
    print_tree(root->right);
}

/*
 * If the root is NULL, return false. If the root's data is greater than the number, search the left
 * subtree. If the root's data is less than the number, search the right subtree. If the root's data is
 * equal to the number, return true
 * 
 * @param root The root of the tree
 * @param number The number to be searched in the tree.
 * 
 * @return a boolean value.
 */
bool search(node *root, int number)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data > number)
    {
        search(root->left, number);
    }
    else if (root->data < number)
    {
        search(root->right, number);
    }
    else
    {
        return true;
    }
}