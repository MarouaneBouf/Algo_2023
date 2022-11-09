#include <stdio.h>
#include <stdlib.h>


typedef struct point
{
    int x;
    int y;
    int z;
    struct point *debut;
    struct point *fin;
}pt;

pt* ajout_debut(pt *origine, int x, int y, int z)
{
    pt *point_ = malloc(sizeof(pt));
    point_->x = x;
    point_->y = y;
    point_->z = z;
    point_->debut = origine;
    point_->fin = NULL;
    origine = point_;
    return origine;
}

pt* ajout_fin(pt *origine, int x, int y, int z)
{
    pt *point_ = malloc(sizeof(pt));
    point_->x = x;
    point_->y = y;
    point_->z = z;
    point_->debut = NULL;

    // Si la liste est vide, On pose le nouveau point comme tete de la liste chainée
    if (origine == NULL)
    {
        point_->fin = NULL;
        origine = point_;
        return origine;
    }
    
    pt *temp = origine;
    while(temp->debut != NULL)
    {
        temp = temp->debut;
    }

    point_->fin = temp;
    temp->debut = point_; 
    return origine;
}

pt* suppression_debut(pt *origine)
{
    origine = origine->debut;
    return origine;
}

pt* suppression_fin(pt *origine)
{
    pt *temp = origine;
    while (temp->debut->debut != NULL)
    {
        temp = temp->debut;
    }
    temp->debut = NULL;
    return origine;
}

void affichage(pt *origine)
{
    pt *temp = origine;
    int k = 0;
    while(temp)
    {
        printf("x%i = (%i, %i, %i)\n",k++,temp->x,temp->y,temp->z);
        temp = temp->debut;
    }
}


int main(void)
{
    pt *origine = NULL;
    origine = ajout_debut(origine,10,23,30);
    origine = ajout_debut(origine,15,65,250);
    origine = ajout_debut(origine,22,312,60);
    origine = ajout_fin(origine,1,236,380);
    origine = suppression_debut(origine);
    origine = suppression_fin(origine);
    affichage(origine);
}