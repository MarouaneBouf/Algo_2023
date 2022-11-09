#include <stdio.h>
#include <stdlib.h>


typedef struct point
{
    int x;
    int y;
    int z;
    struct point *point_suivant;
}pt;

pt* ajout_debut(pt *origine, int x, int y, int z)
{
    pt *point_ = malloc(sizeof(pt));
    point_->x = x;
    point_->y = y;
    point_->z = z;
    point_->point_suivant = origine;
    origine = point_;
    return origine;
}

pt* ajout_fin(pt *origine, int x, int y, int z)
{
    pt *point_ = malloc(sizeof(pt));
    point_->x = x;
    point_->y = y;
    point_->z = z;
    point_->point_suivant = NULL;
    pt *temp = origine;
    if (origine == NULL)
    {
        origine = point_;
        return origine;
    }
    
    while(temp->point_suivant != NULL)
    {
        temp = temp->point_suivant;
    }
    temp->point_suivant = point_;
    return origine;
}

pt* suppression_debut(pt *origine)
{
    origine = NULL;
    return origine;
}

pt* suppression_fin(pt *origine)
{
    pt *temp = origine;
    if (origine == NULL)
    {
        return origine;
    }
    if (origine->point_suivant == NULL)
    {
        origine = origine->point_suivant;
        return origine;
    }
    else
    {
        while (temp->point_suivant->point_suivant != NULL)
        {
            temp = temp->point_suivant;
        }
        temp->point_suivant = NULL;
        return origine;
    }
}

void affichage(pt *origine)
{
    pt *temp = origine;
    int k = 0;
    while(temp)
    {
        printf("x%i = (%i, %i, %i)\n",k++,temp->x,temp->y,temp->z);
        temp = temp->point_suivant;
    }
}


int main(void)
{
    pt *origine = NULL;

    origine = ajout_fin(origine,1,236,380);
    origine = ajout_fin(origine,132,26,90);
    affichage(origine);
    origine = suppression_fin(origine);
    printf("-------------------\n");
    affichage(origine);
}