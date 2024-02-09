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
    
    //c'est vide on peux rien afficher
    if(liste==NULL){
        printf("liste vide\n");
        return;
    }

    //Ne pas changer liste sinon bah on a plus de liste
    Client* index = liste;

    //tant que on a pas atteint un element null on affiche et passe au suivant
    
    do
    {
        printf("%d--> ",index->id);
        index = index->Suivant;
    }
    while (index!=NULL);

    return;
}

float distance(Client * c1 , Client * c2){
    //si on me donne de client qui existe
    if(c1!=NULL&&c2!=NULL){
        //je calcule leur distance cartesiennes a l'aide de math.h
        float x = (c1->x - c2->x);
        float y = (c1->y - c2->y);
        float somme = sqrt(pow(x,2) + pow(y,2));
        return somme;
    }
    //sinon je return 0
    return 0;
}

float distanceDepot(Client * c){
    //si le client existe
    if(c!=NULL){
        //je calcule sa distance par rapport au centre (le depot)
        float x = (c->x);
        float y = (c->y);
        float somme = sqrt(pow(x,2) + pow(y,2));
        return somme;
    }
    return 0;
}

float distanceTotale(Client * liste){
    // si tu me donne une liste nul, je fait rien
    if(liste==NULL){
        printf("liste vide\n");
        return 0;
    }

    //je commence somme par calculer la distance du premiere element par rapport au depot
    float somme = distanceDepot(liste);
    //Ensuite tant que le prochaine element n'est pas null, je calcule la distance et passe au suivant
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

        //je fait ceci car je souhaite retourner le premiere element de la liste (liste)
        // donc je ne dois pas changer liste
        Client* index = liste;

        //le client à inserer n'existe pas, on ne fait rien
        if(c==NULL)return liste;

        //on souhaite inserer au debut de la liste
        if(pos==1){
            //mais la liste est vide
            if(liste==NULL){ 
                liste = c; 
                return liste;
            }

            //mais la liste n'est pas vide
            c->Suivant=liste;
            liste=c;
            return liste;
        }

        //on souhaite inserer a une position autre que la première
        while(pos>2){

            //si il y'as encore un objet apres on avance
            if(index->Suivant!=NULL){
                //l'element que l'on regarde deviens l'element qui le suit
                index=index->Suivant;
                //on rapproche notre pos de 1
                pos--;
            }

            //si l'index sur lequel on viens d'arriver est vide,
            //mais que on est toujours pas à la position souhaité, on vas sortir de la liste donc erreur
            if(index==NULL&&pos>1){
                printf("on est sortie de la liste");
                return liste;
            }
        }
        // on est sortie da la boucle sans erreur, on peut inserer
        c->Suivant = index->Suivant;
        index->Suivant = c;

        //
        return liste;

    }

Client * suppressionClient (Client * liste, int pos){
    //on supprime rien dans du vide
    if(liste==NULL)return liste;

    Client* index = liste;

    //il faut supprimer le premiere element
    if(pos==1){
        liste=liste->Suivant;
        //pas besoin de supprimer le pointeur de c puisque l'on free le c
        free(index);
        return liste;
    }

    //il faut supprimer ailleurs
    Client* precedent ;
    while(pos>1){
        //on sauvegarde l'element
        precedent = index;

        //on verifie que si l'on va avance sur l'element null (dernier element) 
        //c'est que l'on va surement sortir de la liste
        if(index->Suivant==NULL){
            printf("position en dehors de la liste");
            return liste;
        }

        //on avance
        pos--;
        index=index->Suivant;
    }

    //on affilie l'element precedent à l'element suivant
    precedent->Suivant=index->Suivant;

    //on supprime l'element actuel
    free(index);
    return liste;
}

void cleanMemory(Client* Liste){
    Client* index;
    while(Liste!=NULL){
        index=Liste->Suivant;
        free(Liste);
        Liste = index;
    }
    return;
}