#ifndef PILEOPERATEURS_H
#include <stdlib.h>
#include <stdio.h>
#define PILEOPERATEURS_H

typedef struct Operateurs
{
    float valeur;
    struct Operateurs* suivant;

}Operateurs;

Operateurs* initOperateurs(float valeur);

//on empile un float
Operateurs* empilerOperateursChar(float x,Operateurs* pile);

//on empile un element deja de type Operateurs
Operateurs* empilerOperateurs(Operateurs* nouveau ,Operateurs* pile);

//on enleve le dernier element de la liste
Operateurs* depilerOperateurs(Operateurs* pile);

// on affiche la pile...
void afficherPileOperateurs(Operateurs* pile);

float effectuerOperateurs(float a,float b, Operateurs* op);

#endif