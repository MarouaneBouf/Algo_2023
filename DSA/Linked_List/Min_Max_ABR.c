#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
  int data;
  struct maillon *left;
  struct maillon *right;
}maillon;


maillon* new_noeud(int data)
{
    maillon* maillon_1 = (maillon*)malloc(sizeof(maillon));
    maillon_1->data = data;
    maillon_1->left = NULL;
    maillon_1->right = NULL;
 
    return maillon_1;
}


maillon* insert(maillon* maillon_1, int data)
{

    if (maillon_1 == NULL)
        return new_noeud(data);
    else {
        if (data <= maillon_1->data)
            maillon_1->left = insert(maillon_1->left, data);
        else
            maillon_1->right = insert(maillon_1->right, data);
        return maillon_1;
    }
}

int findMin(maillon* maillon_1)
{
    maillon* current = maillon_1;
 
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int findMax(maillon* maillon_1)
{
    maillon* current = maillon_1;
 
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main(void)
{
    maillon* root = NULL;
    root = insert(root, 2);
    insert(root, 7);
    insert(root, 92);
    insert(root, 6);
    insert(root, 1);
    insert(root, 11);
    insert(root, 9);
    insert(root, 4);
 

    printf("Minimum element is %d and Maximum element is %d\n", findMin(root), findMax(root));
}