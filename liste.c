#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Client{
    int id;
    float x;
    float y;
    int quantite;
    struct Client *Suivant;
}Client;


Client* creerClient(int id, int x, int y, int quantite){
    
    Client* c = (Client*)malloc(sizeof(Client));
    c->id =id;
    c->x =x;
    c->y =y;
    c->quantite =quantite;
    c->Suivant = NULL;
    return c;
}

void afficherListe(Client * liste) {

if(liste==NULL){
    printf("liste vide\n");
}
while (liste!=NULL)
{
    printf("%d--> ",liste->id);
    liste = liste->Suivant;
}

fflush(stdout);

}

float distance(Client * c1 , Client * c2){
    if(c1!=NULL&&c2!=NULL){
        int x = (c1->x - c2->x);
        int y = (c1->y - c2->y);
        float somme = sqrt(pow(x,2) + pow(y,2));
        return somme;
    }
    return 0;
}

float distanceDepot(Client * c){
    if(c!=NULL){
        int x = (c->x);
        int y = (c->y);
        float somme = sqrt(pow(x,2) + pow(y,2));
        return somme;
    }
    return 0;
}

float distanceTotale(Client * liste){
    if(liste==NULL){
        printf("liste vide\n");
        return 0;
    }
    int somme = distanceDepot(liste);
    while (liste->Suivant!=NULL)
    {
        somme+= distance(liste,liste->Suivant);
        liste = liste->Suivant;
    }
    return somme;
}

int meilleurePosition(Client * liste, Client * c) {
    //a faire
}

Client * insertionClient(Client * liste, Client * c , int pos){
    if(liste==NULL)return liste;

    if(pos==1){
        c->Suivant=liste;
        liste=c;
        return liste;
    }

    while(pos>1){
        if(liste->Suivant!=NULL){
            pos--;
            liste=liste->Suivant;
        }else{
            printf("position en dehors de la liste");
            return liste;
        }
    }

    if(liste->Suivant!=NULL)
    c->Suivant=liste->Suivant;

    liste->Suivant=c;
    return liste;
}

Client * suppressionClient (Client * liste, int pos){
    if(liste==NULL)return liste;

    Client* c;
    if(pos==1){
        c= liste;
        liste=liste->Suivant;
        free(c);
        return liste;
    }

    while(pos>1){
        if(liste->Suivant!=NULL){
            pos--;
            liste=liste->Suivant;
        }else{
            printf("position en dehors de la liste");
            return liste;
        }
    }
    c = liste->Suivant;

    liste->Suivant = c->Suivant;

    free(c);
    return liste;

}