#include <stdlib.h>
#include <stdio.h>
#include "pileOperateurs.h"

typedef struct Reels
{
    float valeur;
    struct Reels* suivant;

}Reels;

Reels* pileReels;

Operateurs* pileOperateurs;

Reels* initReels(float valeur)
{
    Reels* x = (Reels*)malloc(sizeof(Reels));
    x->valeur=valeur;
    return x;
}

//on empile un float
Reels* empilerFloat(float x,Reels* pile)
{
    Reels* new = initReels(x);
    if(pile==NULL)
    {
        pile=new;
    }
    else
    {
    new->suivant=pile;
    pile=new;
    }

    return pile;
}

//on empile un element deja de type reels
Reels* empilerReels(Reels* nouveau,Reels* pile)
{
    if(pile==NULL)
    {
        pile=nouveau;
    }
    else
    {
    nouveau->suivant=pile;
    pile=nouveau;
    }

    return pile;
}

//on enleve le dernier element de la liste
Reels* depiler(Reels* pile)
{
    Reels* temp=pile;

    pile=pile->suivant;
    temp->suivant=NULL;

    return pile;
}

// on affiche la pile...
void afficherPile(Reels* pile){

    Reels* index = pile;

    while (index!=NULL)
    {
        printf("%f\n",index->valeur);
        index=index->suivant;
    }

}

float evaluer(char expression [])
{

    int i =0;

    Reels* premier;
    Reels* deuxieme;

    while(expression[i]!='\0'){

        Reels* nouveau = initReels(0);
        
        if(expression[i]>='0'&&expression[i]<='9')
        {
            printf("valeur stocker: %f \n",(expression[i]-'0'));
            nouveau->valeur=expression[i]-'0';
        }
        else
        {
            premier = pileReels;
            pileReels = depiler(pileReels);
            deuxieme = pileReels;
            pileReels = depiler(pileReels);

            if (expression[i]=='+')
            {
                nouveau->valeur=deuxieme->valeur+premier->valeur;
            }
            else if (expression[i]=='-')
            {
                nouveau->valeur=deuxieme->valeur-premier->valeur;
            }
            else if (expression[i]=='*')
            {
                nouveau->valeur=deuxieme->valeur*premier->valeur;
            }
            else if (expression[i]=='/')
            {
                if (premier == 0) {
                        printf("Erreur : Division par zéro\n");
                }
                nouveau->valeur=deuxieme->valeur/premier->valeur;
            }
        }
        pileReels = empilerReels(nouveau,pileReels);
        i++;
    }

    printf("Le resultat est: %f\n",pileReels->valeur);
    return pileReels->valeur;
}

float evaluerInfixe(char expression[]){
    int i = 0;
    int resultat=0;
    while(expression[i]!='\0'){
        if(expression[i]>='0'&&expression[i]<='9')
        {
            printf("stocker operandes:%f \n",(expression[i]-'0'));
            pileReels = empilerFloat((expression[i]-'0'),pileReels);
        }
        else if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/')
        {
            printf("stocker operateurs:%c \n",expression[i]);
            pileOperateurs = empilerOperateursChar(expression[i],pileOperateurs);
        }
        else if(expression[i]==')')
        {
            resultat+= effectuerOperateurs(pileReels->suivant->valeur,pileReels->valeur,pileOperateurs);
            pileReels = depiler(pileReels);
            pileReels = depiler(pileReels);
            pileOperateurs = depilerOperateurs(pileOperateurs);
            printf("effectuer operateurs %f \n",resultat);
        }
        i++;
    }
}