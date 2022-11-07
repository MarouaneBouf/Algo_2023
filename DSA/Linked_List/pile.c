#include <stdio.h>
#include <stdlib.h>


typedef struct point
{
    int x;
    int y;
    int z;
    struct point *suivant;
}point;


point *ajouter_pile(point *tete,int x,int y, int z)
{
    point *new_point = malloc(sizeof(point));
    new_point->x = x;
    new_point->y = y;
    new_point->z = z;
    // new_point->suivant = NULL;
    new_point->suivant = tete;
    tete = new_point;
    return tete;
}    

point *supprimer(point *tete)
{
    point *temp = tete;
    tete = tete->suivant;
    free(temp);
    return tete;
}

void affichage(point *tete)
{
    point *temp = tete;
    int k = 0;
    while(temp)
    {
        printf("x%i = (%i, %i, %i)\n",k++,temp->x,temp->y,temp->z);
        temp = temp->suivant;
    }
}

int main(void)
{
    point *pile = NULL;
    pile = ajouter_pile(pile, 10, 12, 19);
    pile = ajouter_pile(pile, 16, 68, 95);
    pile = ajouter_pile(pile, 3213, 21, 6586);
    pile = supprimer(pile);
    affichage(pile);
}