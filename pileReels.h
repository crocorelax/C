#ifndef PILEREELS_H
#include <stdlib.h>
#include <stdio.h>
#define PILEREELS_H

typedef struct Reels
{
    float valeur;
    struct Reels* suivant;

}Reels;

Reels* initReels(float valeur);

//on empile un float
Reels* empilerFloat(float x,Reels* pile);

//on empile un element deja de type reels
Reels* empilerReels(Reels* nouveau ,Reels* pile);

//on enleve le dernier element de la liste
Reels* depiler(Reels* pile);

// on affiche la pile...
void afficherPile(Reels* pile);

float evaluer(char expression []);

float evaluerInfixe(char expression[]);

#endif