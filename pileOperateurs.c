#include <stdlib.h>
#include <stdio.h>

typedef struct Operateurs
{
    char valeur;
    struct Operateurs* suivant;

}Operateurs;

Operateurs* initOperateurs(char valeur)
{
    Operateurs* x = (Operateurs*)malloc(sizeof(Operateurs));
    x->valeur=valeur;
    return x;
}

//on empileOperateurs un float
Operateurs* empilerOperateursChar(char x,Operateurs* pileOperateurs)
{
    Operateurs* new = initOperateurs(x);
    if(pileOperateurs==NULL)
    {
        pileOperateurs=new;
    }
    else
    {
    new->suivant=pileOperateurs;
    pileOperateurs=new;
    }

    return pileOperateurs;
}

//on empileOperateurs un element deja de type Operateurs
Operateurs* empilerOperateurs(Operateurs* new,Operateurs* pileOperateurs)
{
    if(pileOperateurs==NULL)
    {
        pileOperateurs=new;
    }
    else
    {
    new->suivant=pileOperateurs;
    pileOperateurs=new;
    }

    return pileOperateurs;
}

//on enleve le dernier element de la liste
Operateurs* depilerOperateurs(Operateurs* pileOperateurs)
{
    Operateurs* temp=pileOperateurs;

    pileOperateurs=pileOperateurs->suivant;
    temp->suivant=NULL;

    return pileOperateurs;
}

// on affiche la pileOperateurs...
void afficherPileOperateurs(Operateurs* pileOperateurs){

    Operateurs* index = pileOperateurs;

    while (index!=NULL)
    {
        printf("%f\n",index->valeur);
        index=index->suivant;
    }

}

float effectuerOperateurs(float a,float b, Operateurs* op){
    switch (op->valeur)
    {
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        if(b==0){
            printf("division par 0 impossible");
            return 0;
        }
        return a/b;
        break;
    default:
        break;
    }
}